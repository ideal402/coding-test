import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

temp = {}
left = 0
ans = 0 
for right in range(n):
    x = arr[right]

    if x in temp:
        temp[x] += 1
    else:
        temp[x] = 1

    while len(temp) > 2:
        y = arr[left]
        temp[y] -= 1

        if temp[y] == 0:
            del temp[y]
        
        left += 1

    ans = max(ans, right - left + 1)

print(ans)