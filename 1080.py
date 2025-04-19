import sys

def flip(i, j):
    for x in range(i, i+3):
        for y in range(j, j+3):
            if maps1[x][y] == 0:
                maps1[x][y] = 1
            else:
                maps1[x][y] = 0
                
n, m = map(int, sys.stdin.readline().split())

maps1 = []
maps2 = []

for i in range(n):
    temp = str(sys.stdin.readline())
    arr = []
    for j in range(m):
        arr.append(int(temp[j]))
    maps1.append(arr)
    
for i in range(n):
    temp = str(sys.stdin.readline())
    arr = []
    for j in range(m):
        arr.append(int(temp[j]))
    maps2.append(arr)    

cnt = 0

if (n < 3 or m < 3) and maps1 != maps2:
    cnt = -1
else:
    for i in range(n-2):
        for j in range(m-2):
            if maps1[i][j] != maps2[i][j]:
                cnt += 1
                flip(i, j)

if cnt != -1:
    if maps1 != maps2:
        cnt = -1

print(cnt)

