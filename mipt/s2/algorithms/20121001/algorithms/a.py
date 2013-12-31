import sys
a = int(sys.argv[1])
b = int(sys.argv[2])
res = 0
while b > 0:
 i = 0
 while i < (b % 10):
  res += a
  i += 1
 b /= 10
print res
