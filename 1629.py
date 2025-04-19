import sys

a, b, c = map(int, sys.stdin.readline().split())

def solve(a, b):
    if b == 1:
        return a % c
    result = solve(a, b//2)

    if b % 2 == 0:
        return (result*result) % c
    else:    
        return (result*result*a) % c

print(solve(a, b))


