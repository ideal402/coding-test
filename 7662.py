import sys
import heapq as hq

n = int(sys.stdin.readline())

for _ in range(n):
    N = int(sys.stdin.readline())
    max_hp = []
    min_hq = []
    visited = [False] * N

    for i in range(N):
        cmd, num = map(str, sys.stdin.readline().split())
        num = int(num)

        if cmd == "I":
            hq.heappush(min_hq, (num, i))
            hq.heappush(max_hp, (-num, i))
            visited[i] = True

        elif cmd == "D": 
            if num == 1:
                while max_hp and not visited[max_hp[0][1]]:
                    hq.heappop(max_hp)
                
                if max_hp:
                    visited[max_hp[0][1]] = False
                    hq.heappop(max_hp)

            else:
                while min_hq and not visited[min_hq[0][1]]:
                    hq.heappop(min_hq)
                
                if min_hq:
                    visited[min_hq[0][1]] = False
                    hq.heappop(min_hq)

    while max_hp and not visited[max_hp[0][1]]:
        hq.heappop(max_hp)
    while min_hq and not visited[min_hq[0][1]]:
        hq.heappop(min_hq)
    
    if min_hq and max_hp:
        print(-max_hp[0][0], min_hq[0][0])
    else:
        print("EMPTY")