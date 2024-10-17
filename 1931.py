import sys

n = int(sys.stdin.readline())

lst = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

lst.sort(key = lambda x:(x[1], x[0]))

e_t = 0
cnt = 0 
for i in lst:
    if e_t <= i[0]:
        e_t = i[1]
        cnt += 1

print(cnt)
    