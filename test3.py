from collections import deque

q = deque()
v = [False] * 10

def bfs(start):

    q.append(start)
    v[start] = True

    while(q):
        
        n = q.popleft()
        v[n] = True
        dx = n+1
        if  not v[dx]:
            q.append(dx)
            v[dx] = True
    

def dfs(start, v):
    v[start] =True

    dx = start+1

    if not v[dx]:
        dfs(dx, v)

    return start 


parent = [i for i in range(10)]


def find(a):
    
    if parent[a] != a:
        parent[a] = find(a)
    
    return parent[a]

def union(a, b):
    
    ra, rb = find(a), find(b)

    if ra == rb:
        return False
    
    if ra < rb:
        parent[rb] = ra
    else:
        parent[ra] = rb
    
    return True

import heapq
INF = float("inf")

def dijkstra(n, g, start):

    dist = [INF] * n    
    dist[start] = 0
    
    pq = [(0, start)]

    while pq:
        cur_cost, u = heapq.heappop(pq)
        if cur_cost > dist[u]:
            continue

        for v, w in g[u]:
            new_cost = cur_cost + w
            if new_cost < cur_cost:
                dist[v] = new_cost
                heapq.heappush(pq, (new_cost, v))
            
    return dist


