H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()

aL = aR = aU = aD = 0
bL = bR = bU = bD = 0

for c in S:
    if c == 'L':
        aL += 1
    elif c == 'R':
        aR += 1
    elif c == 'U':
        aU += 1
    elif c == 'D':
        aD += 1

for c in T:
    if c == 'L':
        bL += 1
    elif c == 'R':
        bR += 1
    elif c == 'U':
        bU += 1
    elif c == 'D':
        bD += 1

cL = sc - 1
cR = W - sc
cU = sr - 1
cD = H - sr

if cL == 0 and aL != 0:
    ans = False
elif cR == 0 and aR != 0:
    ans = False
elif cU == 0 and aU != 0:
    ans = False
elif cD == 0 and aD != 0:
    ans = False

if aL - bL > cL or aR - bR > cR or\
        aU - bU > cU or aD - bD > cD:
    ans = False
else:
    ans = True
