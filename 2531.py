import sys
from collections import defaultdict
n,d,k,c = map(int, sys.stdin.readline().split())
arr = [int(sys.stdin.readline()) for _ in range(n)]
arr += arr[:k-1]

num = defaultdict(int)
num[c] = 1

for i in range(k):
    num[arr[i]] += 1

ans = len(num)

for i in range(1, n):
    num[arr[i-1]] -= 1

    if num[arr[i-1]] == 0:
        del num[arr[i-1]]
    
    num[arr[i+k-1]] += 1

    ans = max(ans, len(num))

print(ans)