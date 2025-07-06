import sys

n, m  = map(int, sys.stdin.readline().split())

dic = {}

for i in range(n):
    url, pw = map(str, sys.stdin.readline().split())

    if url not in dic:
        dic[url] = pw

for i in range(m):
    temp = str(sys.stdin.readline().strip())
    print(dic[temp])
