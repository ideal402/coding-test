import sys

n, m = map(int, sys.stdin.readline().split())
a = {}
ans = []

for _ in range(n):
    temp = str(sys.stdin.readline().strip())
    a[temp] = 1

for _ in range(m):
    temp = str(sys.stdin.readline().strip())
    if temp in a:
        ans.append(temp)

ans.sort()

print(len(ans))

for x in ans:
    print(x)
