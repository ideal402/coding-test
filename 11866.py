import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
arr = deque(range(1,n+1))

cnt = 0
ans = []
while arr:
    temp = arr.popleft()
    cnt += 1

    if cnt%k==0:
        ans.append(temp)
    else:
        arr.append(temp)
print('<',end='')
print(*ans, sep=", ", end='')
print('>')