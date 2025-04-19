import sys

n = int(sys.stdin.readline())
num = 666
ans = num

while n-1:
    num += 1

    if '666' in str(num):
        ans = num
        n -= 1

print(num)