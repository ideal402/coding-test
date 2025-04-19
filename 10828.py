import sys

command = ['push','pop','size','empty','top']

n = int(sys.stdin.readline())
stack = []

for _ in range(n):
    com = sys.stdin.readline().split()

    if command[0] == com[0]:
        stack.append(int(com[1]))
    elif command[1] == com[0]:
        if stack:
            print(stack.pop())
        else:
            print(-1)
    elif command[2] == com[0]:
        print(len(stack))
    elif command[3] == com[0]:
        if stack:
            print(0)
        else:
            print(1)
    elif command[4] == com[0]:
        if stack:
            print(stack[-1])
        else:
            print(-1)
