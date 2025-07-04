import sys

l, r, c = map(int, sys.stdin.readline().split())

while l != 0 or r != 0 or c != 0:
    l, r, c = map(int, sys.stdin.readline().split())

    maps = []
    for _ in range(l):
        temp = [] 
        for i in range(r): 
            s = list(sys.stdin.readline().strip())
            temp.append(s)
        maps.append(temp)
        span = list(sys.stdin.readline().strip())


    print(maps)