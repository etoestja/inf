import sys

def fastmul(a, b):
 if a == 0 or b == 0:
  return 0
 else:
  if a % 2 == 1:
   c = fastmul((a - 1) / 2, b)
   return c + c + b
  else:
   c = fastmul(a / 2, b)
   return c + c

a = int(sys.argv[1])
b = int(sys.argv[2])
print a, b, fastmul(a, b)
