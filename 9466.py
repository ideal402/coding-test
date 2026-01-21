import sys
sys.setrecursionlimit(10**6)

def dfs(i):
    global ans
    visit[i] = True
    next_node = arr[i]

    if not visit[next_node]:
        dfs(next_node)
    elif not finished[next_node]:
        temp = next_node
        count = 1
        while temp != i:
            temp = arr[temp]
            count += 1
        ans += count
    
    finished[i] = True

a = int(sys.stdin.readline())

for _ in range(a):
    n = int(sys.stdin.readline())
    ans = 0
    visit = [False] * n
    finished = [False] * n

    arr = list(map(lambda x: int(x) - 1, sys.stdin.readline().split()))

    for x in range(n):
        if(not visit[x]): 
            dfs(x)
    
    print(n-ans)

