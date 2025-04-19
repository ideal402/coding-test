import sys

n = int(sys.stdin.readline().strip())
lst = list(map(int, sys.stdin.readline().split()))

lst.sort()


target = 1

for x in lst:
    if target < x:
        break
    target += x

print(target)