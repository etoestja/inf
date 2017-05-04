import numpy as np

a1 = [0.4, 0.4]
a2 = [[0.43, 0.37], [0.45, 0.40]]

r = np.zeros((2,2))

for i in range(2):
    for j in range(2):
        r[i,j] = a1[i] * a2[i][j]

print r
