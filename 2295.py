import sys
from bisect import bisect

n = int(sys.stdin.readline())
arr = []
two = set()

for i in range(n):
    a = int(sys.stdin.readline())
    arr.append(a)

for i in range(n):
    for j in range(n):
        two.add(arr[i]+arr[j])

arr.sort()

found = False
for i in range(n-1, -1, -1):
    if found: break
    for j in range(n):
        target = arr[i] - arr[j]
        
        if target in two:
            print(arr[i])
            found = True
            break
