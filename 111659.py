import sys

n, m = map(int, sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))
arr_sum = [0] * n

for i in range(n):
    arr_sum[i] = arr_sum[i-1] + arr[i]

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())

    if i != 1:
        print(arr_sum[j-1] - arr_sum[i-1-1])
    else:
        print(arr_sum[j-1])
