import random
#n = random.choice(range(2, 101))
n = 100
a = random.sample(range(0, 101) * n, n)
print n
print ' '.join(map(str, a))
