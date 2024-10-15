import sys

n, k, p = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

ans = n

for i in range(n):
    temp = arr[i*k:i*k+k]
    if temp.count(0) >= p:
        ans -= 1

print(ans)