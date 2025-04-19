import sys

N = int(sys.stdin.readline())

stack = []
result = []

for i in range(N):
    x = sys.stdin.readline().split()

    if x[0] == 'push':
        stack.insert(0, x[1])

    elif x[0] == 'pop':
        if stack:
            print(stack.pop(0))
        else:
            print(-1)

    elif x[0] == 'top':
        if stack:
            print(stack[0])
        else:
            print(-1)

    elif x[0] == 'size':
        print(len(stack))

    elif x[0] == 'empty':
        print(0 if stack else 1)

