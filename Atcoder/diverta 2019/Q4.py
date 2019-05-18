N = int(input())

ans = int()

for i in range(1, int(N ** 0.5) + 1):

    if N % i == 0 and i < int(N / i - 1):

        ans += int(N / i) - 1

print(ans)
