import sys

def check(n,x,y):
    first = arr[x][y]

    for i in range(x, n+x):
        for j in range(y, n+y):
            if arr[i][j] != first:
                return False
            
    return True

def slice_arr(n, x, y):    
    for i in range(x, n*3+x, n):
        for j in range(y, n*3+y, n):     
            if check(n, i, j):
                ans[arr[i][j]+1] += 1
            else:
                slice_arr(n//3, i, j)

ans = [0] * 3

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

if not check(n, 0, 0):
    slice_arr(n//3, 0, 0)
else:
    ans[arr[0][0]+1] += 1

for x in ans:
    print(x)

