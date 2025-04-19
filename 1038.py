import sys
from itertools import combinations

#입력 받음
n = int(sys.stdin.readline().strip())

#감소하는 수 리스트 제작
num_list = []

#9876543210 ~ 0 까지의 조합 만들기
# 조합함수를 활용하여 1~10자리 조합을 만듦
for i in range(1, 11):
    temp = combinations("9876543210",i)
    #반환된 조합(튜플)을 합친 후 리스트에 넣음
    for j in temp:
        combination_num = ''
        for k in j: 
            combination_num += str(k)
        num_list.append(int(combination_num))

#작은 수로 정렬
num_list.sort()

#n이 리스트길이 내면 숫자 반환 아닐경우 -1 반환
print(num_list[n] if len(num_list) > n else -1)