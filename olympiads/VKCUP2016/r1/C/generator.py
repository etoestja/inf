from random import random as rand
n = 200000
k = 1000000000
print "%d %d" % (n, k)
for i in range(n):
     print int(((rand() * k)) % (2 * k) - k + 1) ,
