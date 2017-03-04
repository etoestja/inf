from random import *
n = 10000
k = 14
s=' '.join(map(str, sample(range(0, 10001) * 100, n)))
print len(s.split()), k
print s
