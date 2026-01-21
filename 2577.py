import sys

n = 3
ans = 1

for i in range(n):
    temp = int(sys.stdin.readline())
    ans *= temp

arr = [0] * 10

while (ans > 0):
    arr[ans % 10] += 1
    ans = ans // 10

for x in arr:
    print(x)

