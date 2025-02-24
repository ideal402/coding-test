import sys

n = int(sys.stdin.readline())

lst = [list(str(sys.stdin.readline().strip())) for _ in range(n)]

def quad(n,y,x):
    flag = False

    for i in range(n):
        for j in range(n):
            if lst[y][x] != lst[y+i][x+j]:
                flag = True
                break
        if flag:
            break

    if not flag:
        print(lst[y][x], end='')
    else:
        print("(", end='')
        quad(n//2,y,x)
        quad(n//2,y,x+n//2)
        quad(n//2,y+n//2,x)
        quad(n//2,y+n//2,x+n//2)
        print(")", end='')

quad(n,0,0)