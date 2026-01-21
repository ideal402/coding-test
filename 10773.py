import sys

n = int(sys.stdin.readline())
arr = []

for _ in range(n):
    
    i = int(sys.stdin.readline())

    if i > 0:
        arr.append(i)
    else:
        arr.pop()

print(sum(arr))