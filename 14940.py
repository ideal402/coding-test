import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
map_data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# 시작 위치 찾기 (값이 2인 곳)
for i in range(len(map_data)):
    if 2 in map_data[i]:
        start = (i, map_data[i].index(2))

# 최단 거리 배열 (초기값: -1로 설정)
distance = [[-1] * m for _ in range(n)]
distance[start[0]][start[1]] = 0

# BFS 큐 초기화
s = deque([(start[0], start[1])])  # (y, x)

# 방향 벡터 (상, 하, 좌, 우)
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

# BFS 시작
while s:
    cy, cx = s.popleft()  # 현재 위치

    for i in range(4):
        ny, nx = cy + dy[i], cx + dx[i]

        # 범위 안에 있고, 이동 가능한 경우
        if 0 <= nx < m and 0 <= ny < n and map_data[ny][nx] != 0:
            # 방문하지 않았거나, 더 짧은 거리로 갱신 가능한 경우
            if distance[ny][nx] == -1 or distance[ny][nx] > distance[cy][cx] + 1:
                distance[ny][nx] = distance[cy][cx] + 1
                s.append((ny, nx))

# 방문하지 못한 곳은 -1로 설정
for i in range(n):
    for j in range(m):
        if map_data[i][j] != 0 and distance[i][j] == -1:
            map_data[i][j] = -1
        elif distance[i][j] != -1:
            map_data[i][j] = distance[i][j]

# 결과 출력
for row in map_data:
    print(" ".join(map(str, row)))
