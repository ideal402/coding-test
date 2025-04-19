import sys

n = int(sys.stdin.readline())
ans = 0

for i in range(1, n+1):
    temp = str(i)

    for c in ["3", "6", "9"]:
        ans += temp.count(c)


print(ans)