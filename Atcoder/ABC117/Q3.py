N, M = map(int, input().split())
X = [int(x) for x in input().split()]

if N >= M:
    print(0)
    quit()

X.sort()

dX = list()

for i in range(M - 1):
    dX.append(X[i + 1] - X[i])

dX.sort(reverse=True)

print(sum(dX) - sum([dX[i] for i in range(N - 1)]))
