import sys
from collections import deque

answer = 0
n = int(sys.stdin.readline())
maps = []
max_n = 0
min_n = 101
for _ in range(n):
    temp = list(map(int, sys.stdin.readline().split()))
    maps.append(temp)
    max_n = max(max_n, max(temp))
    min_n = min(min_n, min(temp))

for i in range(min_n, max_n+1):

    graph = []
    for j in maps:
        temp = [0 if x > i else 1 for x in j]
        graph.append(temp)

    move = [(0, 1), (1,0), (0, -1), (-1,0)]
    cnt = 2

    visit = [[0] * n for _ in range(n)]


    for y in range(n):
        for x in range(n):
            if graph[y][x] == 0 and not visit[y][x]:
                dq = deque()
                dq.append((x,y))
                graph[y][x] = cnt
                visit[y][x] = True
    
                while dq:
                    cx, cy = dq.popleft()
                    for dx, dy in move:
                        nx, ny = cx+dx, cy+dy

                        if -1 < nx < n and -1 < ny < n:
                            if graph[ny][nx] == 0 and not visit[ny][nx]:
                                graph[ny][nx] = cnt
                                visit[ny][nx] = True
                                dq.append((nx,ny))
                cnt += 1
    
    answer = max(answer, cnt-2)



print(answer)