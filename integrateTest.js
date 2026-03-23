import http from 'k6/http';
import { check, sleep } from 'k6';
import { Rate, Trend } from 'k6/metrics';

// 커스텀 메트릭 (정상 API와 지연 API의 지표를 분리하여 측정)
export const normalApiDuration = new Trend('normal_api_duration');
export const normalApiFailRate = new Rate('normal_api_fail_rate');
export const delayedApiFailRate = new Rate('delayed_api_fail_rate');

export const options = {
  // Scenarios: 서로 다른 트래픽 패턴을 동시에 실행
  scenarios: {
    // 1. 정상 API 트래픽: VUs(Virtual Users)를 일정하게 유지하며 정상적인 시스템 사용을 시뮬레이션
    normal_traffic: {
      executor: 'constant-vus',
      vus: 10,
      duration: '30s',
      exec: 'normalRequest', // 실행할 함수 지정
    },
    // 2. 지연 API 트래픽: Arrival Rate를 급격히 증가시켜 트래픽 스파이크(Spike)를 시뮬레이션
    spike_traffic: {
      executor: 'ramping-arrival-rate',
      startRate: 10,
      timeUnit: '1s',
      preAllocatedVUs: 50,
      maxVUs: 500, // 최대 생성 가능한 VU 수
      stages: [
        { duration: '5s', target: 10 },
        { duration: '10s', target: 200 }, // 초당 200개 요청으로 급증 (장애 유발 구간)
        { duration: '10s', target: 200 }, // 부하 유지
        { duration: '5s', target: 10 },   // 트래픽 감소
      ],
      exec: 'delayedRequest', // 실행할 함수 지정
    },
  },
  // Thresholds: 테스트 통과/실패 기준 (벌크헤드 성공 기준)
  thresholds: {
    // 지연 API에 스파이크가 발생하더라도, 정상 API의 95%는 200ms 이내 응답 및 실패율 1% 미만이어야 함
    'normal_api_duration': ['p(95)<200'],
    'normal_api_fail_rate': ['rate<0.01'],
  },
};

const BASE_URL = 'http://10.178.0.2:8082';

// [Observer] 정상 API 호출 함수
export function normalRequest() {
  // 수정: 무거운 current API 대신, PK 기반의 가벼운 단일 조회 API 호출 (regionId=1 가정)
  const res = http.get(`${BASE_URL}/map/regions/1/basic`); 
  
  normalApiDuration.add(res.timings.duration);
  normalApiFailRate.add(res.status !== 200);
  
  check(res, { 'normal status is 200': (r) => r.status === 200 });
  sleep(1);
}

// [Target] 지연 API 호출 함수 (테스트 대상)
export function delayedRequest() {
  // 환경 변수로 주입받은 엔드포인트를 호출 (기본값: 벌크헤드가 적용된 원본 API)
  const endpoint = __ENV.TARGET_ENDPOINT || '/map/roads/traffic';
  
  // 수정: POST 요청을 위한 Request Body (H3 인덱스 리스트 예시)
  const payload = JSON.stringify([
    '89283082803ffff', 
    '89283082807ffff'
  ]);

  // 수정: HTTP Header 명시 (Content-Type)
  const params = {
    headers: {
      'Content-Type': 'application/json',
    },
  };

  // 수정: http.get 대신 http.post 사용
  const res = http.post(`${BASE_URL}${endpoint}`, payload, params);
  
  delayedApiFailRate.add(res.status !== 200);
  
  // 503(Service Unavailable) 등 Fail-fast 응답도 의도된 동작일 수 있으므로 로깅/체크 기준 세분화 필요
  check(res, { 'delayed request completed': (r) => r.status === 200 || r.status === 503 });
}