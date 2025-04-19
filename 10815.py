import sys

n = int(sys.stdin.readline())

dit= dict()

arr = list(map(int, sys.stdin.readline().split()))

for i in arr:
    if i not in dit:
        dit[i] = 1

n = int(sys.stdin.readline())
c_arr = list(map(int, sys.stdin.readline().split()))

for i in c_arr:
    if i in dit:
        print(1, end=" ")
    else:
        print(0, end=" ")
