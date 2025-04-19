import sys

n = int(sys.stdin.readline())

ans = 0
for i in range(1,n+1):
    temp = sum(map(int, str(i)))
    
    if i%temp == 0:
        ans += 1

print(ans)