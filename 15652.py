import sys
from itertools import combinations


n, m = map(int, sys.stdin.readline().split())

arr = [i+1 for i in range(n)]

ans = []

def iter(cnt, s):
    if m == cnt:
        print(*ans)
        return
    
    for i in range(s, n):
        ans.append(arr[i])
        iter(cnt+1, i)
        ans.pop()


    return 

iter(0, 0)