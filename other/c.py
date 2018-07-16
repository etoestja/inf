import numpy as np

def count_proba(k):
  n = 0
  for i in range(k):
      if np.random.rand() <= 2 ** (-n):
          n += 1
  return 2 ** n - 1

def count_proba_med(k, R = 100):
  arr = [count_proba(k) for _ in range(R)]
  return np.mean(arr)

print(count_proba_med(10000, R = 100))
