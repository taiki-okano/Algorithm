N, M = map(int, input().split())
A = [int(x) for x in input().split()]

matches = [2, 5, 5, 4, 5, 6, 3, 7, 6]

A.sort()
min_match = 8
max_number = 0
for i, a in enumerate(A):
    if min_match > matches[a - 1]:
        min_match = matches[a - 1]
        max_number = a

ans = list()
for i in range(N // min_match):
    ans.append(max_number)

surplus = N % min_match

upper = 0
lower = N // min_match - 1

matches = list(map(lambda x: x - min_match, matches))

A.reverse()
for a in A:
    if surplus >= matches[a - 1] and matches[a - 1] != 0:
        for i in range(surplus // matches[a - 1]):
            if a > max_number:
                ans[upper] = a
                upper += 1
            else:
                ans[lower] = a
                lower -= 1
        surplus %= matches[a - 1]

print("matches : {}".format(matches))
print("surplus : {}".format(surplus))
print(str(ans))
