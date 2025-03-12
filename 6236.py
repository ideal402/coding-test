import sys

n, m = map(int, sys.stdin.readline().split())
arr = [0]*n

for i in range(n):
    arr[i] = int(sys.stdin.readline())
    
low = min(arr)
high = sum(arr)

while low <= high:
    mid = (low+high)//2
    cnt = 1
    cash = mid

    for i in arr:
        if cash < i:
            cnt += 1
            cash = mid
        cash -= i

    if cnt > m or mid < max(arr):
        low = mid+1        
    else:
        high = mid-1
        k = mid

print(k)
