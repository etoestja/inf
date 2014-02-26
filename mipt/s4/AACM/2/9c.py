a=1
b=1
c=1
i=1
N=2014

while i <= N:
 print i, a + b + c
 (a, b, c) = (a + b, a + b + c, b + c)
 i += 1
