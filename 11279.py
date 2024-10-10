import sys
import heapq

n = int(sys.stdin.readline())

arr = []
for _ in range(n):
    temp = int(sys.stdin.readline())
    if temp == 0:
        if arr:
            print(-heapq.heappop(arr))
        else:
            print(0)
    else:
        heapq.heappush(arr, -temp)
