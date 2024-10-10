import sys

n = int(sys.stdin.readline())
arr = [int(sys.stdin.readline())]

for _ in range(n-1):
    num = int(sys.stdin.readline())
    
    for i in range(len(arr)):
        if num <= arr[i]:
            arr.insert(i, num)
            break
        if i == len(arr)-1:
            arr.append(num)

for i in arr:
    print(i)
     