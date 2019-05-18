N = int(input())
L = [int(x) for x in input().split()]

if sum(L) - max(L) > max(L):
    print("Yes")
else:
    print("No")
