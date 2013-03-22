n=10000
k=10
m=100000
print n
print k

for i in range(0, n):
 print i
 print k
 for si in range(0, k):
  print si

print m

for i in range(0, m):
 print (i % n) + 1
 print k
 for si in range(0, k):
  print si
