import sys

n = int(sys.stdin.readline())

arr=[int(sys.stdin.readline()) for _ in range(n)]

mx=max(arr)
ans = 0
temp = 0
for i in range(len(arr)-1, -1, -1):
    if arr[i] == max:
        ans += 1
        break
    elif arr[i] > temp:
        ans += 1
        temp = arr[i]

print(ans)