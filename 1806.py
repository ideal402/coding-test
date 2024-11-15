import sys

n, x = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

i, j, s, l = 0, 0, 0, 0
ans = float("inf")

while j < n:
    s += arr[j]
    l += 1

    while s >= x:
        ans = min(ans, l)
        s -= arr[i]
        i += 1
        l -= 1
    
    j += 1

if ans == float('inf'):
    print(0)
else:
    print(ans)