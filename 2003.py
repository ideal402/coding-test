import sys

n,m = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

i=0
j=0
cnt = 0
s = 0

while j < n :
    s += arr[j]
    
    while s >= m:
        if s == m:
            cnt += 1
        s -= arr[i]
        i += 1
    
    j += 1

print(cnt)
    
    