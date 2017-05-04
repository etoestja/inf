import numpy as np

a1 = [0.2, 0.4, 0.4]
a2 = [[0.03, 0.95, 0.02], [0.43, 0.20, 0.37], [0.45, 0.15, 0.40]]

r = np.zeros((3,3))

for i in range(3):
    for j in range(3):
        r[i,j] = a1[i] * a2[i][j]

print r
