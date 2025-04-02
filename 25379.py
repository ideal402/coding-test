import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr2 = arr.copy()
cnt = 0

for i in range(n):
    for j in range(n - 1 - i):
        if arr[j] % 2 == 1 and arr[j + 1] % 2 == 0:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
            cnt += 1

cnt2 = 0
for i in range(n):
    for j in range(n - 1 - i):
        if arr2[j] % 2 == 0 and arr2[j + 1] % 2 == 1:
            arr2[j], arr2[j + 1] = arr2[j + 1], arr2[j]
            cnt2 += 1

print(min(cnt, cnt2))
