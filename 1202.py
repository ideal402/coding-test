import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())

jewel = []

for _ in range(n):
    m, v = map(int, input().split())

    jewel.append((m, v))

jewel.sort()

bag = []

for _ in range(k):
    bag.append(int(input()))

bag.sort()

ans = 0
tmp_jewel = []
j_idx = 0


for bag_cap in bag:
    
    while j_idx < n and jewel[j_idx][0] <= bag_cap:
        heapq.heappush(tmp_jewel, -jewel[j_idx][1])
        j_idx += 1

    if tmp_jewel:
        ans += -heapq.heappop(tmp_jewel)

print(ans)
