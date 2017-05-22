import itertools
from math import factorial
from copy import deepcopy
n = 6
k = n // 2
assert(n % 2 == 0)
V = list(itertools.combinations(range(1, n + 1), k))
LV = len(V)
print V, LV

E = [[0 for _ in range(LV)] for _ in range(LV)]
E0 = (0, 0)
for (i, j) in itertools.product(range(LV), range(LV)):
    I = set(V[i]).intersection(V[j])
#    print i, j, V[i], V[j], I, len(I)
    if len(I) == 0:
        print i, j
        E[i][j] = 1
        E0 = (i, j)

print E[19][0]

def get_path(i, j, visited = None):
    if visited == None:
        visited = [0 for _ in range(LV)]
    if i == j:
        return [i]
    if visited[i]:
        return None
    visited[i] = 1
    for k in range(LV):
        if E[i][k] == 1:
            pp = get_path(k, j, visited)
            if pp == None:
                continue
            else:
                return [i] + pp
    return None

print '\n'.join(map(lambda x : repr(x), E))

for (i, j) in itertools.product(range(LV), range(LV)):
    print i, j, get_path(i, j)

for i in range(LV):
    p1 = get_path(i, E0[0])
    p2 = get_path(i, E0[1])
    if (p1 == None) and (p2 == None):
        print i, j, "ERROR none"
    elif (p1 == None) and (not p2 == None):
        print i, 2, p2
    elif (not p1 == None) and (p2 == None):
        print i, 1, p1
    else:
        print i, j, "ERROR both", p1, p2

#print get_path(19, 0)

#print factorial(n) / factorial(k) / factorial(n - k)
