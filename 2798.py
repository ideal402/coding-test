import sys
from itertools import combinations
n, m = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

temp = list(combinations(arr, 3))

ans = 0

for i in temp:
    sum_n = sum(i)
    if sum_n <= m:
        ans = max(ans, sum_n)

print(ans)