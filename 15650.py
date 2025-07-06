import sys
from itertools import combinations

n,m = map(int, sys.stdin.readline().split())

a = [i for i in range(1, n+1)]

for i in combinations(a, m):
    print(*i)