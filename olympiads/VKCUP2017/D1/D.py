import sys
sys.stdin.readline()
s = raw_input()

pos = 0
ans = [[0] * (5 * len(s)) for i in xrange(5 * len(s))]

def print_me(c, cp, depth):
    global pos
    global ans
    if (cp == '[') & (c == ']'):
        pos += 3
    height = (max_depth - depth) * 2 + 1
    if (c == '['):
        ans[pos][depth] = 1
        ans[pos + 1][depth] = 2
        ans[pos][depth + height + 1] = 1
        ans[pos + 1][depth + height + 1] = 2
    else:
        ans[pos][depth] = 1
        ans[pos - 1][depth] = 2
        ans[pos][depth + height + 1] = 1
        ans[pos - 1][depth + height + 1] = 2

    for i in xrange(height):
        ans[pos][depth + i + 1] = 3
    pos += 1

depth = [0] * len(s)
N = 0
i = 0
deep = 0
max_depth = 0
for c in s:
    if c == '[':
        depth[i] = N
        N += 1
    if c == ']':
        N -= 1
        depth[i] = N
    if (N - 1 > max_depth):
        max_depth = N - 1
    i += 1

c = '#'
for i in xrange(len(s)):
    print_me(s[i], c, depth[i])
    c = s[i]

for j in xrange(max_depth * 2 + 3):
    s = ''
    for i in xrange(pos):
        if ans[i][j] == 0:
            s += ' '
        if ans[i][j] == 1:
            s += '+'
        if ans[i][j] == 2:
            s += '-'
        if ans[i][j] == 3:
            s += '|'
    print s

