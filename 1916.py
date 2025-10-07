import sys

input = sys.stdin.readline
INF = float('inf')

n = int(input())
m = int(input())

graph = [[INF] * n for _ in range(n)]

for _ in range(m):
    u, v, cost = map(int, input().split())
    graph[u-1][v-1] = min(graph[u-1][v-1], cost)

start, end = map(int, input().split())
start -= 1
end -= 1

dist = [INF] * n
visited = [False] * n

dist[start] = 0

def get_smallest_index():
    min_val = INF
    idx = -1
    for i in range(n):
        if not visited[i] and dist[i] < min_val:
            min_val = dist[i]
            idx = i
    return idx

for _ in range(n):
    u = get_smallest_index()
    if u == -1:
        break
    visited[u] = True

    for v in range(n):
        if not visited[v] and graph[u][v] != INF:
            if dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]

print(dist[end])
