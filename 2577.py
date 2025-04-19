import sys

a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())

dic = {i:0 for i in range(0,10)}

temp = a*b*c

for i in str(temp):
    dic[int(i)] += 1

for key, item in dic.items():
    print(item)