import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

stack = []
ans = []

for x in reversed(arr):
    
    while stack and stack[-1] <= x:
        stack.pop()
    
    ans.append(stack[-1] if stack else -1)
    
    stack.append(x)

print(*ans[::-1])