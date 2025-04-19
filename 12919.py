import sys

s = str(sys.stdin.readline().strip())
t = str(sys.stdin.readline().strip())

result = 0

def dfs(t_str):
    global result
    
    if t_str == s:
        result = 1
        return
    
    if len(t_str) == 0:
        return
    
    if t_str[-1] == "A":
        dfs(t_str[:-1])
        
    if t_str[0] == "B":
        dfs(t_str[1:][::-1])
        
dfs(t)

print(result)