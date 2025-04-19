import sys

n = int(sys.stdin.readline())

lst = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
dp = [0] * (n+1)

for i in range(n-1,-1,-1):
    if lst[i][0]+i <= n:
        dp[i] = max(lst[i][1] + dp[i+lst[i][0]], dp[i+1]) 
    else:
        dp[i] = dp[i+1]
print(dp[0])