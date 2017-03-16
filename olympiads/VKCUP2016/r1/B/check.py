import sys
sys.stdin = open(sys.argv[1], "r")
n, d, h = map(int, raw_input().split(' '))
p = [0] * (n+1)
l = []
sys.stdin = open(sys.argv[2], "r")
for i in xrange(n-1):
    t = map(int, raw_input().split(' '))
    if (t[0] < 0):
        exit(0)
    a, b = t[0], t[1]
    if a == 1:
        l += [b]
    else:
        p[a] = b
    if (a < 0) | (b < 0) | (a > n) | (b > n):
        exit(1)


def get_len(v):
    i = 0
    while (v != 0):
        v = p[v]
        i += 1
    return i

ans = map(get_len, l)
ans.sort()
if (ans[-1] + ans[-2]) != d:
    print "Wrong d", (ans[-1] + ans[-2]), '!=', d
    exit(1)
if (ans[-1]) != h:
    print "Wrong h", (ans[-1]), '!=', h
    exit(1)
if sum(ans) != n - 1:
    print "Wrong sum", sum(ans), '!=', n - 1
    exit(1)
exit(0)
