import sys
import math
a, b, n = map(int, sys.stdin.readline().split())

for _ in range(n):
    num = a//b
    a = (a % b)*10
print(a//b)