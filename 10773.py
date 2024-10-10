import sys

n = int(sys.stdin.readline())
arr = []
for _ in range(n):
    temp = int(sys.stdin.readline())

    if temp == 0:
        arr.pop()
    else:
        arr.append(temp)

if arr:
    print(sum(arr))
else:
    print(0)