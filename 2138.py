import sys

n = int(sys.stdin.readline())

def change(i, lst):
    if i == n-1:
        for j in range(-1, 1):
            if lst[i+j] == 0:
                lst[i+j] = 1
            else:
                lst[i+j] = 0
    else:
        for j in range(-1, 2):
            if lst[i+j] == 0:
                lst[i+j] = 1
            else:
                lst[i+j] = 0

current = []
want = []

temp = sys.stdin.readline().strip()
current = [int(x) for x in temp]
want = [int(x) for x in sys.stdin.readline().strip()]

ans = -1

# 0번을 눌렀을 때
cnt = 0
for i in range(2):
    if current[i] == 0:
        current[i] = 1
    else:
        current[i] = 0
cnt += 1

for i in range(n-1):
    if current[i] != want[i]:
        change(i+1, current)
        cnt += 1
if current == want:
    ans = cnt

# 0번을 안눌렀을 때
cnt = 0
current = [int(x) for x in temp] 
for i in range(n-1):
    if current[i] != want[i]:
        change(i+1, current)
        cnt += 1
if current == want:
    if ans == -1:
        ans = cnt
    else:
        ans = min(ans, cnt)

print(ans)
