import sys
from collections import deque


def bfs(start):
    visit = [0] * (n+1)
    ans = [0] * (n+1)
    q = deque()
    cnt = 0
    q.append((start, 0))
    visit[start] = 1

    while q:
        cur, cnt = q.popleft()
        for i in maps[cur]:
            if not visit[i]:
                visit[i] = 1
                ans[i] = cnt + 1
                q.append((i, cnt+1))

    return ans

n = int(sys.stdin.readline())
maps = list([] for _ in range(n+1))

while True:
    a, b = map(int, sys.stdin.readline().split())
    if a == -1 and b == -1:
        break
    maps[a].append(b)
    maps[b].append(a) 

answer = [0] * (n+1)

for i in range(1, n+1):
    answer[i] = max(bfs(i))

min_ans = min(answer[1:])

print(min_ans, answer.count(min_ans))

print(*[i for i in range(1, len(answer)) if answer[i] == min_ans])
