import sys

def self_num(n):
    temp = n
    for i in str(n):
        temp += int(i)
    
    return temp

non_self_num = set()

for i in range(1, 10000):
    next_num = self_num(i)
        
    while next_num < 10000 and next_num not in non_self_num:
        non_self_num.add(next_num)
        next_num = self_num(next_num)

for i in range(1,10000):
    if i not in non_self_num:
        print(i)