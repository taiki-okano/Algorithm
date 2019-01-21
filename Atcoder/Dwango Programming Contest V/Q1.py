N = int(input())
a = list(map(int, input().split()))

average = sum(a) / len(a)

min_diff = abs(a[0] - average)
ans = 0
for i, x in enumerate(a):
    if min_diff > abs(x - average):
        min_diff = abs(x - average)
        ans = i

print(ans)
