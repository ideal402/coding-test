import sys

n = int(sys.stdin.readline())

dp = [-1]*5001
dp[3] = 1
dp[5] = 1

for i in range(6, n+1):
    a,b = -1,-1

    if dp[i-3] != -1:
        a = dp[i-3]+1
    if dp[i-5] != -1:
        b = dp[i-5]+1
    
    if a > 0 and b > 0:
        dp[i] = min(a,b)
    elif a > 0:
        dp[i] = a
    elif b > 0:
        dp[i] = b

print(dp[n])

# gpt 정리

n = int(sys.stdin.readline())
dp = [-1]*(n+1)

if n>=3:
    dp[3] = 1
if n>=5:
    dp[5] = 1

for i in range(6, n+1):
    if dp[i-3] != -1:
        dp[i] = dp[i-3]+1
    if dp[i-5] != -1:
        dp[i] = min(dp[i], dp[i-5]+1) if dp[i] != -1 else dp[i-5] + 1
    
                   
print(dp[n])
