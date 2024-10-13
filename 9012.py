import sys

n = int(sys.stdin.readline())

for _ in range(n):
    temp = sys.stdin.readline().strip()
    stack = []
    isBreak = False
    for s in temp:
        if s == "(":
            stack.append(s)
        else:
            if stack:
                if stack.pop() != "(":
                    print("NO")
                    isBreak = True
                    break
            else:
                print("NO")
                isBreak = True
                break
    if not isBreak:
        if stack:
            print("NO")
        else:
            print("YES") 