import sys

n, m = map(int, sys.stdin.readline().split())

arr = []

for _ in range(n):
    arr.append(int(sys.stdin.readline()))

arr.sort()

l, r = 0, 0
ans = int(2000000000)

while l <= r and r < n:

    if arr[r] - arr[l] < m:
        r += 1

    else:
        ans = min(ans, arr[r] - arr[l])
        l += 1

print(ans)