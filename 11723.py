import sys

cmd = ["add", "remove", "check", "toggle", "all", "empty"]

n = int(sys.stdin.readline())
s = [0]* 21

for _ in range(n):
    lst = list(map(str, sys.stdin.readline().split()))
    
    if cmd.index(lst[0]) == 0:
        s[int(lst[1])] = 1
    
    elif cmd.index(lst[0]) == 1:
        s[int(lst[1])] = 0
    
    elif cmd.index(lst[0]) == 2:
        print(s[int(lst[1])])

    elif cmd.index(lst[0]) == 3:
        if s[int(lst[1])] == 1:
            s[int(lst[1])] = 0
        else:
            s[int(lst[1])] = 1
    
    elif cmd.index(lst[0]) == 4:
        s = [1]*21
        
    else:
        s = [0]*21

