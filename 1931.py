import sys

# 선택 절차: 회의실의 시작시간을 정렬
n = int(sys.stdin.readline())

lst = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
lst.sort(key = lambda x: (x[1], x[0]))

# 적절성 검사: 회의가 끝나고 시작가능한 회의가 있는지 확인
# 해답검사: 회의가 끝나고 시작가능한 회의가 있는지 확인
i = 0
cnt = 0
end = 0

while i < len(lst):
    if lst[i][0] >= end:
        end = lst[i][1]
        cnt += 1
    i += 1

print(cnt)
