import sys

input_num = int(sys.stdin.readline())
num = 1
i = 1

while num < input_num:
    num += 6*i
    i += 1

print(i)