N=1000
K=100000

Kc=0

print N
print K

i=j=k=0

while i < N:
 j=0
 if j == N:
  break
 while j < N:
  k=0
  while k < N:
   if Kc > K:
    j = N
    break
   print i
   print j
   print k
   Kc += 1
   k += 1
  j += 1
 i += 1

print 1
print 1
print N
