import sys

n, m, k = map(int, sys.stdin.readline().split())

lst = [i for i in range(1,n+1)]

if m+k-1 <= n <= m*k:
    sub = []
    temp = lst[0:k]
    lst = lst[k:]
    temp.sort(reverse=True)
    for x in temp:
        sub.append(x)
    n = n-k
    m -= 1
    
    while m>0:
        temp = lst[0:n//m]
        lst = lst[n//m:]
        temp.sort(reverse=True)
        for x in temp:
            sub.append(x)
        n -= n//m
        m -= 1

    print(*sub)

else:
    print(-1)