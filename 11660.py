import sys

n, m = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

arr_sum = [[0] * (n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        arr_sum[i][j] = arr[i-1][j-1] + arr_sum[i-1][j] + arr_sum[i][j-1] - arr_sum[i-1][j-1]

for _ in range(m):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

    ans = arr_sum[x2][y2] - arr_sum[x1-1][y2] - arr_sum[x2][y1-1] + arr_sum[x1-1][y1-1]

    print(ans)
