import sys

n = int(sys.stdin.readline())

# 입출입 명단 디셔너리 선언
name_dict = {}

# 명단 업데이트
for _ in range(n):
    name, enter = map(str, sys.stdin.readline().split())

    #이름이 명단에 없으면 추가
    if name in name_dict:
        name_dict[name] = enter
    #있을 때 상태변경
    else:
        name_dict[name] = enter

#들어와 있는 사람 리스트 선언
enter_list = []

# 명단에서 입장인 사람 리스트에 추가 
for name in name_dict:
    if name_dict[name] == "enter":
        enter_list.append(name)

# 사전 역순 정렬
enter_list.sort(reverse=True)

for i in enter_list:
    print(i)