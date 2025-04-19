import sys

n , k = map(int, sys.stdin.readline().split())

cost = [int(sys.stdin.readline()) for _ in range(n)]

cost = cost[::-1]
cnt = 0
i=0

while k > 0:
    num = k // cost[i]
    k = k%cost[i]
    cnt += num
    i += 1

print(cnt)