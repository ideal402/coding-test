import sys

N,R,C = map(int, sys.stdin.readline().split())
result =0

def find(n, x, y):
    global result
    if x == R and y == C:
        print(result)
        return
    
    if not(x<= R <x+n and y <= C < y+n):
        result += n*n
        return
    
    find(n//2, x, y)
    find(n//2, x, y + n//2)
    find(n//2, x + n//2, y)
    find(n//2, x + n//2, y + n//2)

find(2**N, 0, 0)
