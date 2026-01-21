import sys
from collections import deque

def bfs( x, y):
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    q = deque()
    q.append((x, y))
    visit[y][x] = 1

    while(q):
        cx, cy = q.popleft()

        water_count = 0
        for i in range(4):
            nx, ny = cx + dx[i], cy+dy[i]

            if 0 < nx < m and 0 < ny < n:
                if ice[ny][nx] == 0:
                    water_count += 1
                elif ice[ny][nx] > 0 and not visit[ny][nx]:
                    q.append((nx, ny))
                    visit[ny][nx] = 1
            
            if water_count > 0:
                ice[cy][cx] -= water_count
                
                if ice[cy][cx] < 0:
                    ice[cy][cx] = 0



n, m = map(int, sys.stdin.readline().split())

visit = [[-1] * m] * n
ice = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]



print("-------------")
for x in ice:
    print(x)
cnt = 0
flag = False

for i in range(n):
    for j in range(m):
        if ice[i][j] != 0:
            bfs(ice, j, i)
            flag = True
            break
        if flag: break
        

for x in ice:
    print(x)

for i in range(n):
    for j in range(m):
        if ice[i][j] != 0:
            bfs(ice, j, i)
            flag = True
            break
        if flag: break
print("-------------")

for x in ice:
    print(x)
