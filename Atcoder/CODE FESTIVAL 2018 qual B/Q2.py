N, X = map(int, input().split())

ans = 0
M = 0
for i in range(N):
    a, b = map(int, input().split())
    M = max(M, b)
    ans += a * b

print(ans + X * M)
