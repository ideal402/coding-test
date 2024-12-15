import sys

N, m = map(int, sys.stdin.readline().split())
ans = []
visit = [0] * N

def dfs(n):
    if n == m:
        print(*ans)
        return
    
    for i in range(N):

        if visit[i]:
            continue
            
        visit[i] = 1
        ans.append(i+1)

        dfs(n+1)

        ans.pop()
        visit[i] = 0

dfs(0)
