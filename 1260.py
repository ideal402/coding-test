import sys
from collections import deque
n, m, v = map(int, sys.stdin.readline().split())

graph = {}

for i in range(n):
    graph[i+1] = []

for _ in range(m):
    start, end = map(int, sys.stdin.readline().split())

    if end not in graph[start]:
        graph[start].append(end)
    
    if start not in graph[end]:
        graph[end].append(start)
    
for i in graph:
    temp = graph[i]
    temp.sort()
    graph[i] = temp

visited = set()

def dfs(node):

    if node not in visited:
        print(node, end=" ")
        visited.add(node)

        for neighbor in graph[node]:
            dfs(neighbor)

def bfs(node):
    visited = set()
    queue = deque([node])

    while queue:
        node = queue.popleft()
        
        if node not in visited:
            print(node, end=" ")
            visited.add(node)

            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

dfs(v)
print('')
bfs(v)
