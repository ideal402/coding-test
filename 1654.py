import sys

k,n = map(int, sys.stdin.readline().split())

arr = [int(sys.stdin.readline()) for i in range(k)]

arr.sort()

start = 1
end = arr[-1]

while start <= end:
    mid = (start+end)//2
    cnt = 0
    for i in arr:
        cnt += i//mid

    if cnt >= n:
        start = mid + 1
    else:
        end = mid - 1

print(end)