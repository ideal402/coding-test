import sys

n = int(sys.stdin.readline())

arr = [0] * 10

while(n>0):
    arr[n%10] += 1
    n //= 10

temp = arr[6] + arr[9]
arr[6] = 0
arr[9] =  temp//2 if temp%2 == 0 else temp//2 + 1

print(max(arr))