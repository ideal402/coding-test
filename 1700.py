import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())

concent = []

order = deque(map(int, sys.stdin.readline().split()))

answer = 0

while order:
    num = order.popleft()

    if num in concent:
        continue
    
    if len(concent) < n:
        concent.append(num)
    else:
        temp = []
        for i in concent:
            if i in order:
                temp.append(order.index(i))
            else:
                temp.append(101)

        concent.pop(temp.index(max(temp)))
        concent.append(num)
        answer += 1

print(answer)
