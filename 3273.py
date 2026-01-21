import sys

n = int(sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))

x = int(sys.stdin.readline())

check = [0] * 2000001

cnt = 0

for a in arr:
    if check[x-a] == 1:
        cnt += 1
    else:
        check[a] = 1

print(cnt)
