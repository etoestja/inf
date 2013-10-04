import sys
M=50
N=50
def pm():
 print str(M)+" "+str(N)
 i=0
 while i < M:
  j = 0
  while j < N:
   sys.stdout.write(str(i+j))
   if j < N - 1:
    sys.stdout.write(";")
   j += 1
  print ""
  i += 1
pm()
pm()
