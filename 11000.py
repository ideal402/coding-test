import sys
import heapq

#변수 입력
n = int(sys.stdin.readline())
s_t = list(list(map(int, sys.stdin.readline().split())) for _ in range(n))

# 시간순 정렬
s_t.sort()

# 힙큐 선언 및 초기화
hq = []
answer = 1
heapq.heappush(hq, 0)

#시간표에 대해
for i in s_t:
    # 가장 빨리 끝나는 시간 반환
    end_t = heapq.heappop(hq)
    
    # 다음 시작시간이 빨리 끝나는 시간 보다 뒤면
    if i[0] >= end_t:
        # 끝나는 수업 시간 추가
        heapq.heappush(hq, i[1])
    # 다음 시작이 빨리 끝나는 시간보다 빠르면
    else:
        # 가장 빨리 끝나는 시간 추가
        heapq.heappush(hq, end_t)
        # 강의실 추가
        answer += 1
        # 다음 강의의 끝나는 시간 추가
        heapq.heappush(hq, i[1])


print(answer)