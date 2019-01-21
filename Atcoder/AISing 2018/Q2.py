N = int(input())
A, B = map(int, input().split())

counts = [0, 0, 0]

P = map(int, input().split())

for p in P:
    if p <= A:
        counts[0] += 1
    elif p <= B:
        counts[1] += 1
    else:
        counts[2] += 1

print(min(counts))
