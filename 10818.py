import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

ans_min = arr[0]
ans_max = arr[0]

for i in arr[1:]:
    if ans_max < i:
        ans_max = i
    if ans_min > i:
        ans_min = i

print(ans_min, ans_max)