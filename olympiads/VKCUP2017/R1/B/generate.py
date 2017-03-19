from random import random as rand
from random import sample

n = sample(range(2, 50), 1)[0]
k = sample(range(2, n - 1), 1)[0]
print("%d %d" % (n, k))


for i in range(n - k + 1):
    is_Y = rand() > 0.5
    if is_Y:
        print "YES"
    else:
        print "NO"
