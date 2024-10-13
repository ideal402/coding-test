import sys

n, k = map(int, sys.stdin.readline().split())
remain = n - k*(k+1)//2

if remain < 0:
    print(-1)
else:
    if remain % k:
        print(k)
    else:
        print(k-1)

    