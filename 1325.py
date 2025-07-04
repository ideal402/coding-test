import sys
from collections import deque

def bfs(start):
    q = deque([start])
    visited = [0] * (n+1)
    count = 0
    visited[start] = 1

    while q:
        v = q.popleft()
        count += 1

        for i in nodes[v]:
            if not visited[i]:
                q.append(i)
                visited[i] = 1
        
    return count

n, m = map(int, sys.stdin.readline().split())

nodes = list([] for _ in range(n+1))

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    nodes[b].append(a)

connected = [0] * (n+1)

for i in range(1, n+1):
    connected[i] = bfs(i)

max_count = max(connected)

ans = [i for i in range(1, n+1) if connected[i] == max_count]

print(*ans)