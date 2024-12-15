import sys

n = int(sys.stdin.readline())
base_s = list(str(sys.stdin.readline().strip()))
ans = 0

for _ in range(n-1):
    s = str(sys.stdin.readline().strip())
    temp = base_s[:]
    cnt = 0
    
    for j in s:
        if j in temp:
            temp.remove(j)
        else:
            cnt += 1

    if cnt < 2 and len(temp) <2:
        ans += 1


print(ans)