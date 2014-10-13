from math import *

x0=4.457
x1=5.466
x2=6.695
x3=8.198

y0=2.2
y1=2.4
y2=2.6
y3=2.8

x=5.

a=y0*(x-x1)*(x-x2)*(x-x3)/(x0-x1)/(x0-x2)/(x0-x3)+y1*(x-x0)*(x-x2)*(x-x3)/(x1-x0)/(x1-x2)/(x1-x3)+y2*(x-x0)*(x-x1)*(x-x3)/(x2-x0)/(x2-x1)/(x2-x3)+y3*(x-x0)*(x-x1)*(x-x2)/(x3-x0)/(x3-x1)/(x3-x2)
print a
b=asinh(x)
print b, (a-b)
