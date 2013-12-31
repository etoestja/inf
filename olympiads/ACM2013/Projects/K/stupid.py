a=(2**31-1)
b=(2**31-1)
i=1
N=5
Const=(2**31)
A=(2**31-1)
B=(2**31-1)
C=(2**31-1)
while i <= N:
 t = (A * a + B * b + C) % Const
 print t
 a=b
 b=t
 i+=1
