import sys
from collections import deque

sys.setrecursionlimit(10**6)

def dfs(cur):
    for nxt in adj[cur]:
        if p[cur] == nxt: continue
        p[nxt] = cur
        dfs(nxt)

n = int(sys.stdin.readline())

p = [0]*(n+1)
adj = [[] for _ in range(n+1)]

for _ in range(n-1):
    u, v = map(int, sys.stdin.readline().split())

    adj[u].append(v)
    adj[v].append(u)

dfs(1)

for i in range(2, n+1):
    print(p[i])
