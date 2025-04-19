import sys
from collections import deque
n = int(sys.stdin.readline().strip())

board = []

for _ in range(n):
    temp = str(sys.stdin.readline().strip())
    temp_arr = []
    for i in temp:
        temp_arr.append(int(i))
    board.append(temp_arr)

visit = [[0 for _ in range(n)] for _ in range(n)]
town_num = 1

next_visit = deque()
answer = []

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for y in range(n):
    for x in range(n):
        temp_ans = 0 

        if visit[y][x] == 0 and board[y][x] == 1:
            next_visit.append((x, y))
            visit[y][x] = 1
            town_num += 1

            while next_visit:
                cx,cy = next_visit.popleft()
                
                if board[cy][cx] == 1:
                    board[cy][cx] = town_num
                    temp_ans +=1

                    for i in range(4):
                        nx = cx + dx[i]
                        ny = cy + dy[i]
                        if 0 <= nx < n and 0 <= ny < n and visit[ny][nx] == 0 and board[ny][nx] == 1:
                            next_visit.append((nx, ny))
                            visit[ny][nx]
        if temp_ans>0:
            answer.append(temp_ans)

answer.sort()

print(len(answer))

for i in answer:
    print(i)


    