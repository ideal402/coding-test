import sys

n = str(sys.stdin.readline().strip())

cnt = 0
i = 0

while i < len(n):
    cnt += 1
    com = str(cnt)
    
    for j in com:
        if i<len(n) and n[i] == j:
            i += 1

        
print(cnt)