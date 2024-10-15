import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
ans = float("inf")

for i in range(n-1):
    for j in range(i+1, n):
        diff = (arr[j] - arr[i])/(j-i)

        if diff - int(diff) != 0:
            continue

        start = arr[i] - diff * i
        cnt = 0
        
        for k in range(n):
            if arr[k] != start:
                cnt += 1
            start += diff
        
        ans = min(ans, cnt)

print(ans)            
