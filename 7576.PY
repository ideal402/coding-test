import sys
from collections import deque

m, n = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for i in range(n)]
dist = [[-1] * m for i in range(n)]
q = deque()
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for i in range(n):
    for j in range(m):
        if board[i][j] == 1:
            dist[i][j] = 0 
            q.append([i, j])
        if board[i][j] == -1:
            dist[i][j] = -2

while(q):
    cx, cy = q.popleft()

    for i in range(4):
        nx = cx+dx[i]
        ny = cy+dy[i]

        if(nx > -1 and nx < n and ny > -1 and ny < m and dist[nx][ny] < 0 and board[nx][ny] != -1):
            dist[nx][ny] = dist[cx][cy] + 1
            q.append([nx, ny])

ans = -1

for i in range(n):
    for j in range(m):
        if dist[i][j] == -1:
            print(-1)
            exit()
        ans = max(ans, dist[i][j])
        
print(ans)