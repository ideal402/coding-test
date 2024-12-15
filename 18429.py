import sys
# from itertools import permutations

# n, k = map(int, sys.stdin.readline().split())

# lst = list(map(int, sys.stdin.readline().split()))

# per = list(permutations(lst))
# cnt = 0

# for i in per:
#     w = 500

#     for j in i:
#         w = w - k + j
#         if w < 500:
#             break 
#     if w > 500:
#         cnt += 1

# print(cnt)

N, k = map(int, sys.stdin.readline().split())

lst = list(map(int, sys.stdin.readline().split()))

visit = [0] * N
ans = 0

def dfs(n, w):
    global ans

    if w < 500:
        return

    if n == N:
        ans += 1
        return

    for i in range(N):
        
        if visit[i]:
            continue

        visit[i] = 1

        dfs(n+1, w-k+lst[i])

        visit[i] = 0

dfs(0, 500)

print(ans)