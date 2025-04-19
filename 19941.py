import sys

n, k = map(int, sys.stdin.readline().split())

t = sys.stdin.readline().strip()
cnt = 0
check = []
for i in t:
    if i=="H":
        check.append(1)
    else:
        check.append(0)

for i in range(n):
    if t[i] == "P":
        for j in range(i-k, i+k+1):
            if 0 <= j < n:
                if check[j] == 1:
                    check[j] = 0
                    cnt += 1
                    break


print(cnt)
                
