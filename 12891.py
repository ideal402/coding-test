import sys

s, p = map(int, sys.stdin.readline().split())
word = sys.stdin.readline().strip()
check = list(map(int, sys.stdin.readline().split())) 

pw_c = [0,0,0,0]
ans = 0
for i in range(p):
    if word[i] == "A":
        pw_c[0] += 1
    elif word[i] == "C":
        pw_c[1] += 1
    elif word[i] == "G":
        pw_c[2] += 1
    elif word[i] == "T":
        pw_c[3] += 1


def check_val():
    return pw_c[0] >= check[0] and pw_c[1] >= check[1] and pw_c[2] >= check[2] and pw_c[3] >= check[3]


if check_val():
    ans += 1

for i in range(p, s):
    if word[i-p] == "A":
        pw_c[0] -= 1
    elif word[i-p] == "C":
        pw_c[1] -= 1
    elif word[i-p] == "G":
        pw_c[2] -= 1
    elif word[i-p] == "T":
        pw_c[3] -= 1

    if word[i] == "A":
        pw_c[0] += 1
    elif word[i] == "C":
        pw_c[1] += 1
    elif word[i] == "G":
        pw_c[2] += 1
    elif word[i] == "T":
        pw_c[3] += 1

    if check_val():
        ans += 1

print(ans)