import sys
from collections import deque

n = int(sys.stdin.readline().strip())

#이동할 보드 선언
arr = []
for _ in range(n):
    arr.append([0]*n)

#시작지점 세팅
arr[0][0] = 1


#사과 배치
k = int(sys.stdin.readline().strip())

for _ in range(k):
    x, y = map(int, sys.stdin.readline().split())
    arr[x-1][y-1] = 2


#명령어 배열 선언
c = int(sys.stdin.readline().strip())

commend = deque()

for _ in range(c):
    d, h = sys.stdin.readline().split()
    commend.append((int(d), h))


#다음 명령어 가져옴
change_cnt, change_dir = commend.popleft()

#이동 방향 선언
dx, dy = 0, 0

#좌,하,우,상 이동방향 지정
head = [(1, 0), (0, 1), (-1, 0), (0, -1)]

#이동방향 지정할 숫자
cnt = 0

#뱀이 차지하는 점 저장
s_body = deque()
s_body.append((0,0))

#와일문 탈출 변수 
breaker = False

answer = 0

#뱀이 보드위에 있을 때
while not breaker:

    answer += 1
    
    #머리의 위치 업데이트
    dx += head[cnt][0]
    dy += head[cnt][1]

    #머리가 보드를 넘을 경우
    if dx >= n or dx < 0 or dy >= n or dy < 0:
        breaker = True
        break
    #머리가 뱀 몸에 닿을경우
    elif arr[dy][dx] == 1:
        breaker = True
        break
    #머리가 사과를 먹으면
    elif arr[dy][dx] == 2:
        arr[dy][dx] = 1
        s_body.append((dx, dy))
    #이외
    else:
        arr[dy][dx] = 1
        #현재 머리 좌표를 뱀의 몸 위치에 저장
        s_body.append((dx, dy))
        
        #꼬리가 지나간 자리 초기화
        tx, ty = s_body.popleft()
        arr[ty][tx] = 0

    #방향전환 시간이 되면
    if change_cnt == answer:

        #오른쪽 회전
        if change_dir == 'D':
            cnt += 1
            if cnt == 4:
                cnt = 0
        #왼쪽회전
        else:
            cnt -= 1
            if cnt == -1:
                cnt = 3
        
        #다음 방향전환시간 업데이트
        try:
            change_cnt, change_dir = commend.popleft()
        except:
            continue


print(answer)

        
    