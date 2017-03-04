from random import *
n = 100000
k = 9
s=' '.join(map(str, sample(range(0, 10001) * 100, n - 1)))+' 10000'
#s=' '.join(map(str, map(lambda x: x%10000, range(0, n))))
print len(s.split()), k
print s
