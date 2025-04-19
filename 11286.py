import sys
import heapq as hq
n = int(sys.stdin.readline())
a = []


for i in range(n):
    temp = int(sys.stdin.readline())

    if temp == 0:
        if a:
            temp2 = hq.heappop(a)
            print(temp2[1])
        else:
            print(0)
    else:
        hq.heappush(a, (abs(temp),temp))

