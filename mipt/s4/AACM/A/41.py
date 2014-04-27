def g(n):
 return(((1 + 2 ** 0.5) ** (n + 1) + (1 - 2 ** 0.5) ** (n + 1)) / 2.)

i = 0
N = 10
while i <= N:
 print str(i) + ': ' + str(g(i))
 i += 1
