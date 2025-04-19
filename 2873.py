import sys

n,m = map(int, sys.stdin.readline().split())
maps = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
loc = [0,0]
R_flag = 1
D_flag = 0
min_value = float('inf')
min_index = [0,0]
if n%2 == 0 and m%2 == 0:
    
    for i in range(n):
        if i%2 == 0:
            for j in range(1, m, 2):
                if maps[i][j] < min_value:
                    min_value = maps[i][j]
                    min_index = [i, j] 
        else:
            for j in range(0, m, 2):
                if maps[i][j] < min_value:
                    min_value = maps[i][j] 
                    min_index = [i, j] 
    print(min_index)
        
    
    
else:
    while loc[0] != n-1 or loc[1] != m-1:
        if R_flag:
            if loc[0] < m-1:
                print("R", end="")
                loc[0] += 1
            else:
                print("D", end="")
                loc[1] += 1
                R_flag = 0
        else:
            if loc[0] > 0:
                print("L", end="")
                loc[0] -= 1
            else:
                print("D", end="")
                loc[1] += 1
                R_flag = 1
        