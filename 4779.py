import sys

def task(n):
    if n == 1:
        return "-"

    left = task(n//3)
    center = " " * (n//3)

    return left+center+left


while True:
    try:
        n = int(sys.stdin.readline())
        print(task(pow(3, n)))
    except:
        break