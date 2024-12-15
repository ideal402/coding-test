import sys

n = int(sys.stdin.readline())

maps = [[0 for _ in range(n)] for _ in range(n)]

def check(x, y):
    for i in range(n):
        maps[y][i] = 1
        maps[i][x] = 1
        
        if 0 <= y+i < n and 0 <= x+i < n:
            maps[y+i][x+i] = 1
        if 0 <= y+i < n and 0 <= x-i < n:
            maps[y+i][x-i] = 1
        if 0 <= y-i < n and 0 <= x+i < n:
            maps[y-i][x+i] = 1
        if 0 <= y+i < n and 0 <= x-i < n:
            maps[y-i][x-i] = 1

ans = 0

while any(0 in row for row in maps):
    for i in range(n):
        for j in range(n):
            if maps[i][j] == 0:
                check(j, i)
                for k in maps:
                    print(k)
                print()