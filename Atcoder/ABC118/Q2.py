N, M = map(int, input().split())

foods = [0 for i in range(M)]

for i in range(N):
    inputs = list(map(int, input().split()))

    for j in range(inputs[0]):
        foods[inputs[j + 1] - 1] += 1

ans = 0
for food in foods:
    if food == N:
        ans += 1

print(ans)
