import sys

s = sys.stdin.readline().strip()

dic = {i:0 for i in range(26)}

for c in s:
    dic[ord(c)-97] += 1

for i in dic.values():
    print(i, end=' ')

