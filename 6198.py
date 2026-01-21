import sys
from collections import deque

n = int(sys.stdin.readline())

arr = []

for _ in range(n):
    arr.append(int(sys.stdin.readline()))

stack = []
ans = 0

for h in arr:
    
    while stack and stack[-1] <= h:
        stack.pop()

    ans += len(stack)

    stack.append(h)

print(ans)
