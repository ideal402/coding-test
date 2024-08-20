import sys

n,m = map(int, input().split())
visit_list = [0] * 200001


def BFS(n):
    num_list = [[n, 0,[n]]]
    
    if n > m:
        return n-m, [int(x) for x in range(n,m-1,-1)]
    
    while num_list:
        x, cnt, move = num_list.pop(0)

        if x == m:
            return cnt, move
        
        arr = [x-1, x+1, x*2]
        
        for a in arr:
            if 0<=a<=100000 and visit_list[a] == 0:
                visit_list[a] = 1
                new_move = move + [a]
                num_list.append([a, cnt+1, new_move])


ans_cnt, ans_move = BFS(n)

print(ans_cnt)
for i in ans_move:
    print(i, end=" ")