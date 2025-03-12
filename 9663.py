import sys
def check(k):

    global n, cnt

    if k == n:
        cnt += 1
        return
    
    for i in range(n):
        if not used[i] and not used_up[i+k] and not used_down[(n-1)+k-i]:
            used[i] = 1
            used_up[i+k] = 1
            used_down[(n-1)+k-i] = 1
            check(k+1)            
            used[i] = 0
            used_up[i+k] = 0
            used_down[(n-1)+k-i] = 0
    

n = int(sys.stdin.readline())
maps = [[0]*n for _ in range(n)]

used = [0]*n
used_up = [0]*((n*2)+1)
used_down = [0]*((n*2)+1)

cnt = 0

check(0)
print(cnt)