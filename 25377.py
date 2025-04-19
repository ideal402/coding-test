import sys

n = int(sys.stdin.readline())

ans = float('inf')
for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())

    if a <= b:
        ans = min(ans, b)
if ans == float('inf'):
    print(-1)
else:
    print(ans)