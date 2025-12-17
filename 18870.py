import sys
from bisect import bisect_left

n = sys.stdin.readline()
arr = list(map(int, sys.stdin.readline().split()))
arr2 = set()

for a in arr:
    arr2.add(a)

arr2 = list(arr2)
arr2.sort()

for x in arr:
    print(bisect_left(arr2,x), end=" ")
