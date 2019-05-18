flag = True

N = int(input())
S = list()

ans = 0
a_end = 0
b_start = 0

for i in range(N):

    s = input()

    ans += s.count("AB")

    if s[0] == 'B':
        b_start += 1

        if flag and s[-1] != 'A':
            flag = False

    if s[-1] == 'A':
        a_end += 1

        if flag and s[0] != 'B':
            flag = False

ans += min(a_end, b_start)

if flag and a_end != 0:
    ans -= 1

print(ans)
