import sys

n = int(sys.stdin.readline())

lst = list(map(int, sys.stdin.readline().split()))
maps  = [0]*(n-1)
maps.append(1)
cnt = 0

for i in range(len(lst)-1,-1,-1):
    temp = 0
    for j in range(i, len(lst)):
        if lst[j] < lst[i]:
            if temp < maps[j]:
                temp = maps[j]
    maps[i] = temp+1 

print(max(maps))
