import sys

def pre(p):
    print(chr(p+ord("A")), end="")
    if lc[p] != "." : pre(ord(lc[p]) - ord("A"))
    if rc[p] != "." : pre(ord(rc[p]) - ord("A"))


def inorder(p):
    if lc[p] != "." : inorder(ord(lc[p]) - ord("A"))
    print(chr(p+ord("A")), end="")
    if rc[p] != "." : inorder(ord(rc[p]) - ord("A"))

def post(p):
    if lc[p] != "." : post(ord(lc[p]) - ord("A"))
    if rc[p] != "." : post(ord(rc[p]) - ord("A"))
    print(chr(p+ord("A")), end="")

n = int(sys.stdin.readline())

lc = ["."] * (n+1)
rc = ["."] * (n+1)

for _ in range(n):
    root, lc_name, rc_name = map(str, sys.stdin.readline().split())

    idx = ord(root) - ord("A") 

    lc[idx] = lc_name
    rc[idx] = rc_name

pre(0)
print("")
inorder(0)
print("")
post(0)