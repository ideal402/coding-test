import sys
from itertools import combinations

n, k = map(int, sys.stdin.readline().split())
arr = []
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    arr.append((x,y))



comb = list(combinations(arr, k))

ans = float("inf")

#모든 조합에 대해서
for c in comb:
    dists = []
    #모든 집에서
    for j in arr:
        temp_dist = float("inf")
        #가장 작은 거리
        for i in range(k):        
            temp_dist = min(temp_dist, abs(c[i][0]-j[0]) + abs(c[i][1]-j[1]))
        dists.append(temp_dist)
    # print(dists)
    ans = min(ans, max(dists))
print(ans)
