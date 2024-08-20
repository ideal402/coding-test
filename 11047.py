import sys

n , k = map(int, sys.stdin.readline().split())

cost = []

for _ in range(n):
    cost.append(int(sys.stdin.readline().strip()))

cost.sort(reverse=True)
cnt = 0
i=0

while k>0:
    num = k // cost[i]
    k = k%cost[i]
    cnt += num
    i += 1

print(cnt)