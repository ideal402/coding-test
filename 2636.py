import sys
from collections import deque

n,m = map(int, sys.stdin.readline().split())

c = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dx = [1, -1, 0, 0] 
dy = [0, 0, 1, -1] 

def bfs(x,y):
    q = deque()
    q.append((x,y))
    v = [[0] * m for _ in range(n)]
    melt = set()
    v[y][x] = 1

    while q:
        cx, cy = q.popleft()

        for i in range(4):
            nx, ny = cx+dx[i], cy+dy[i]

            if 0 <= nx < m and 0 <= ny < n and v[ny][nx] == 0:
                if c[ny][nx] == 0:
                    q.append((nx, ny))
                    v[ny][nx] = 1
                else:
                    melt.add((nx, ny))
    melt = list(melt)

    for x, y in melt:
        c[y][x] = 0
    
    return len(melt)

def has_cheese():
    for row in c:
        if 1 in row:
            return True
    return False

temp = []        
ans = 0

while has_cheese():
    temp.append(bfs(0, 0))
    ans += 1

print(ans)
print(temp[-1])

