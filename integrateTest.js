import http from 'k6/http';
import { check, sleep } from 'k6';
import { SharedArray } from 'k6/data';

// H3 인덱스 데이터 로드 (메모리 최적화를 위해 SharedArray 사용)
const h3Indices = new SharedArray('h3 indices', function () {
    return JSON.parse(open('./h3-data.json')); 
});
const payload = JSON.stringify(h3Indices);

export const options = {
    // k6 scenarios 기능을 사용하여 두 종류의 트래픽을 독립적으로 발생시킵니다.
    scenarios: {
        // 1. 병목 유발 시나리오: 느린 API 호출로 서블릿 스레드 고갈 유도
        slow_traffic_scenario: {
            executor: 'ramping-vus',
            startVUs: 0,
            stages: [
                { duration: '30s', target: 100 }, // 웜업 및 스레드 풀 점유 시작
                { duration: '2m', target: 100 },  // 서블릿 스레드 풀(예: 50) 초과 유도
                { duration: '30s', target: 0 },
            ],
            exec: 'callSlowApi', // 실행할 함수 지정
        },
        // 2. 가용성 검증 시나리오: 스레드 고갈 상황에서 정상 API가 응답하는지 확인
        fast_current_scenario: {
            executor: 'ramping-vus',
            startVUs: 0,
            stages: [
                { duration: '30s', target: 20 },
                { duration: '2m', target: 20 },
                { duration: '30s', target: 0 },
            ],
            exec: 'callFastApi', // 실행할 함수 지정
        },
    },
    // 시나리오별로 독립적인 성공 기준(Thresholds) 설정
    thresholds: {
        // 정상 API(current)는 다른 API의 병목과 무관하게 1초 이내 응답 및 실패율 0% 유지 목표
        'http_req_duration{scenario:fast_current_scenario}': ['p(95)<1000'],
        'http_req_failed{scenario:fast_current_scenario}': ['rate==0'],
    },
};

const BASE_URL = 'http://10.178.0.2:8082';

// 🎯 테스트 대상 컨트롤러 경로 설정 (테스트 시 주석을 번갈아 해제하여 비교)
// const TARGET_PATH = '/sync/map';   // [테스트 1] 기존 동기/블로킹 컨트롤러 (장애 전파 확인용)
const TARGET_PATH = '/async/map';     // [테스트 2] 비동기 요청 처리 컨트롤러 (장애 격리 확인용)

// 실행 함수 1: 느린 API (traffic) 호출
export function callSlowApi() {
    const params = {
        headers: { 'Content-Type': 'application/json' },
        timeout: '30s' // 타임아웃 명시적 설정
    };
    const res = http.post(`${BASE_URL}${TARGET_PATH}/roads/traffic`, payload, params);
    
    check(res, { 'traffic API is status 200': (r) => r.status === 200 });
    sleep(1);
}

// 실행 함수 2: 빠른 정상 API (current) 호출
export function callFastApi() {
    const url = `${BASE_URL}${TARGET_PATH}/current?regionId=1&minLat=37.4&maxLat=37.7&minLon=126.8&maxLon=127.2`;
    const res = http.get(url, { timeout: '5s' }); // 클라이언트 타임아웃 5초 가정
    
    check(res, { 'current API is status 200': (r) => r.status === 200 });
    sleep(1);
}


// 벌크헤드용 시나리오

// import http from 'k6/http';
// import { check, sleep } from 'k6';
// import { SharedArray } from 'k6/data';

// // H3 인덱스 데이터 로드 (메모리 최적화를 위해 SharedArray 사용)
// const h3Indices = new SharedArray('h3 indices', function () {
//     return JSON.parse(open('./h3-data.json')); 
// });

// const payload = JSON.stringify(h3Indices);

// const params = {
//     headers: { 'Content-Type': 'application/json' },
//     timeout: '30s', // 느린 API를 위해 넉넉히 설정
// };

// export const options = {
//     // k6 scenarios 기능을 사용하여 두 종류의 트래픽을 독립적으로 발생시킵니다.
//     scenarios: {
//         // 병목 유발: 150명의 VU가 비동기로 동작하는 도로 트래픽 API를 지속 호출
//         slow_traffic_scenario: {
//             executor: 'constant-vus',
//             vus: 150,
//             duration: '2m',
//             exec: 'callSlowApi',
//         },
//         // 가용성 확인: 20명의 VU가 동기로 동작하는 일반 API를 호출
//         fast_current_scenario: {
//             executor: 'constant-vus',
//             vus: 20,
//             duration: '2m',
//             exec: 'callFastApi',
//         },
//     },
//     thresholds: {
//         'http_req_failed{scenario:fast_current_scenario}': ['rate<0.01'], // 정상 API 실패율 1% 미만 목표
//     },
// };

// const BASE_URL = 'http://10.178.0.2:8082';

// export function callSlowApi() {
//     const res = http.post(`${BASE_URL}/map/roads/traffic`, payload, params);
    
//     check(res, {
//         'traffic API status is 200': (r) => r.status === 200,
//     });
//     sleep(1);
// }

// // 실행 함수 2: 빠른 정상 API (current) 호출
// export function callFastApi() {
//     const url = `${BASE_URL}/map/current?regionId=1&minLat=37.4&maxLat=37.7&minLon=126.8&maxLon=127.2`;
    
//     // 중복 호출을 제거하고 타임아웃 5초를 적용하여 1회만 호출합니다.
//     const res = http.get(url, { timeout: '5s' }); 
    
//     check(res, {
//         'current API status is 200': (r) => r.status === 200,
//         'current API response time < 1s': (r) => r.timings.duration < 1000,
//     });
//     sleep(1);
// }