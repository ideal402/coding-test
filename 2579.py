import sys

n = int(sys.stdin.readline().strip())

if n == 0:
    print(0)
    sys.exit()

lst = [0] + [int(sys.stdin.readline().strip()) for _ in range(n)]

if n == 1:
    print(lst[1])
    sys.exit()

dp = [0] * (n+1)

dp[1] = lst[1]
dp[2] = lst[1] + lst[2]

for i in range(3, n+1):
    dp[i] = max(dp[i-3] + lst[i] + lst[i-1], dp[i-2] + lst[i])

print(dp[n])
