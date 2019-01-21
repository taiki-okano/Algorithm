A = int(input())
B = int(input())

ans = B
for i in range(2, 100):
    if B * i > A:
        break
    else:
        ans = B * i

print(ans)
