import sys

n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
lst.sort()

for i in range(1, n):
    lst[i] = lst[i-1]+lst[i]
    

print(sum(lst))

