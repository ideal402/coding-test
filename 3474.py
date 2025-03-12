import sys

n = int(sys.stdin.readline())

for _ in range(n):
    a = int(sys.stdin.readline())
    ans = 0
    while a >= 5:
        a //= 5
        ans += a
    print(ans) 
    
