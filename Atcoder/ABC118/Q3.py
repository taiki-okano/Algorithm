N = int(input())
A = [int(x) for x in input().split()]

A.sort()

m = A[0]

while True:
    flag = True
    new = list()
    for a in A:
        tmp = a % m
        if tmp != 0 and tmp < m:
            new.append(tmp)
            flag = False

    if flag:
        break
    else:
        m = min(new)

print(m)
