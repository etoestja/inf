from math import factorial as ff
def f(N):
 return 10**100*ff(N-500)*ff(N-70)/ff(N-567)/ff(N)

N = 11660
p = 0
while N <= 100000:
    c = f(N)
    print N, f(N), (c > p)
    p = c
    N += 1
