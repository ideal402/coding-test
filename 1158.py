import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())

arr = deque(range(1, n+1))

cnt = 0

ans = "<"
while(len(arr) > 1):
    cnt += 1

    temp = arr.popleft()

    if cnt % k == 0:
        ans += str(temp) + ", "
    else:
        arr.append(temp)
    
ans += str(arr[0]) + ">"

print(ans)