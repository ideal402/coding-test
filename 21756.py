import sys

n = int(sys.stdin.readline())

arr = [i for i in range(1,n+1)]

while len(arr) > 1:
    temp = []
    for i in range(1, len(arr), 2):
        temp.append(arr[i])
    arr = temp

print(arr[0])