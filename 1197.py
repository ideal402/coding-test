import sys

sys.setrecursionlimit(100000)

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(x, y, parent):
    r_x = find(parent, x)
    r_y = find(parent, y)

    if r_x == r_y:
        return False
    
    parent[r_y] = r_x
    return True

def kruskal(edge, n):
    mst = []
    t_w = 0
    parent = list(range(n+1))

    for u, v, w in edge:
        if union(u, v, parent):
            mst.append((u, v, w))
            t_w += w

    return t_w

n, m = map(int, sys.stdin.readline().split())
edges = []

for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().split())
    edges.append((u, v, w))

edges.sort(key = lambda x: x[2])

print(kruskal(edges, n))
