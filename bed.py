L=188.
delta=1.1
N=12.
a=6.
Delta=(L-2*a)/(N-1)

i=1
while i <= N:
 xi=a+(i-1)*Delta
 yi=xi-delta
 print i, xi, yi
 i += 1
