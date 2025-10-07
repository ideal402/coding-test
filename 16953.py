import sys

a, b = map(int, sys.stdin.readline().split())

arr = [(b, 1)]
ans = float('inf')

while(arr):
    num, cnt = arr.pop()
    if num <= 0:
        continue
    
    if num == a:
        ans = min(ans, cnt)

    if num % 10 == 1:
        arr.append((num//10, cnt+1))
    
    if num % 2 == 0:
        arr.append((num//2, cnt+1))
    
if ans == float('inf'):
    print(-1)
else:
    print(ans)
