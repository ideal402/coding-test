import sys
sys.setrecursionlimit(10**6)
n, m = map(int, sys.stdin.readline().split())
maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
dp = [[-1]* m for _ in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x,y):
    if x == m-1 and y == n-1:
        return 1
    if dp[y][x] != -1:
        return dp[y][x]
    
    dp[y][x] = 0
    
    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]

        if 0 <= nx < m and 0 <= ny < n and maps[y][x] > maps[ny][nx]:
            dp[y][x] += dfs(nx, ny)

    return dp[y][x]

print(dfs(0,0))