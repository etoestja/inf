from random import random as rand
from random import sample
n = 150
k = 1
q = 100
print("%d %d %d" % (n, k, q))

T = sample(xrange(n), n)
for i in range(n):
    print T[i],

print ''

X2 = sample(xrange(1, n + 1), q)
X1 = sample(xrange(1, n + 1), q)

for i in range(q):
    tp = (int(rand() > 0.5) + 1)
    idx = X1[i]
    if tp == 2:
        idx = X1[q - i - 1]
    print("%d %d" % (tp, idx))
