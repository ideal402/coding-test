import sys

n = int(sys.stdin.readline())

arr = [list(sys.stdin.readline().split())]

for _ in range(n-1):
    arr.append(list(sys.stdin.readline().split()))

arr.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for i in arr:
    print(i[0])