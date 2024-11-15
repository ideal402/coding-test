import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline())
arr2 = list(map(int, sys.stdin.readline().split()))

def bi(arr, k):
    left = 0
    right = len(arr)-1

    while left <= right:    
        mid = (left+right)//2

        if arr[mid] == k:
            return 1
        elif arr[mid] > k:
            right = mid-1
        else:
            left = mid + 1

    return 0

arr.sort()

for i in arr2:
    print(bi(arr, i))