import sys

n,m = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

ans = 0

for i in range(1, len(arr)-1):
    l_max = max(arr[:i+1])
    r_max = max(arr[i:])

    ans += min(l_max, r_max) - arr[i]

print(ans)

