import sys

[n, k] = map(int, sys.stdin.readline().split())
A = map(int, sys.stdin.readline().split())

P = 0

print(n, k)

PMAX = 2 ** n

d = 1

for i in xrange(n + 1):
    d * (A[i]) % 2
    d *= 2

print(P)

r = 0
for i in range(n + 1):
#    print(i)
    if (P % (2 ** i)) == 0:
#        print("down")
        b = A[i] - (P / (2 ** i))
        if abs(b) <= k and (i != n or b != 0):
#            print("abs")
#            print("i = %d b = %d" % (i, b))
            r += 1

print(r)
