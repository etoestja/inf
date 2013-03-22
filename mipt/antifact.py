from math import *
l = 1
r = 1000
x = int(input())

while (r - l) > 1:
 m = int((l + r) / 2)
 if factorial(m) > x:
  r = m
 else:
  l = m
print l
