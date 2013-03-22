N = 5
res=""
print N, 1, 5	
for a in range(1, N+1):
 for b in range(1, N+1):
  if a == b:
   res.append("-1")
