import sys

n, m = map(int, sys.stdin.readline().split())
arr = {}
arr2 = []
for i in range(n):
    temp = str(sys.stdin.readline().strip())
    if temp not in arr:
        arr[temp] = i+1
        arr2.append(temp)

for i in range(m):
    temp = str(sys.stdin.readline().strip())

    if temp in arr:
        print(arr[temp])
    else:
        print(arr2[int(temp)-1])