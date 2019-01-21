A, B, C = map(int, input().split())

ans = B

ans += min(A + B + 1, C)

print(ans)
