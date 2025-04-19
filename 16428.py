import sys

a, b = map(int, sys.stdin.readline().split())

q = a//b
r = a%b

if r < 0:
    q+=1
    r+=abs(b)

print(q)
print(r)
