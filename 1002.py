import sys
import math
n = int(sys.stdin.readline())

for _ in range(n):
    x1, y1, r1, x2,y2, r2 = map(int, sys.stdin.readline().split())

    length = math.sqrt(((x1-x2)**2 + (y1-y2)**2))
    
    if length == 0:
        if r1 == r2:
            print(-1)
        else:
            print(0)
    elif length > r1+r2:
        print(0)
    elif length == r1+r2:
        print(1)
    elif  abs(r1-r2) < length < r1+r2:
        print(2)
    elif abs(r1-r2) == length:
        print(1)
    else:
        print(0)