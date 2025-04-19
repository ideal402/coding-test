import sys

n, x = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

cnt = 0

for i in range(x):
    cnt += arr[i]

ans = [cnt]

for i in range(1, n-x+1):
    cnt = cnt - arr[i-1] + arr[i+x-1]
    ans.append(cnt)

if max(ans) == 0:
    print("SAD")
else:
    print(max(ans))
    print(ans.count(max(ans)))
