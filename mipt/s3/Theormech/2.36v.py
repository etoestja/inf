from math import *
def mine(phi0,w,t,w0,R):
 phi=phi0*sin(w*t)
 phit=phi0*cos(w*t)*w
 theta=-w0*t**2/(2*R)
 x=(w0*t*sin(phi+theta)-R*phit*sin(phi+theta))
 y=w0*t-w0*t*cos(phi+theta)+R*phit*cos(phi+theta)
 return((x**2+y**2)**0.5)

def theirs(phi0,w,t,w0,R):
 phi=phi0*sin(w*t)
 phi1=phi0*sin(w*t)-w0*t**2/(2.*R)
 x=R*phi0*w*cos(w*t)-2*w0*t*sin(phi1/2.)**2
 y=w0*t*sin(phi1)
 return((x**2+y**2)**0.5)

phi0=1123.
w=1123.
t=10123.
w0=10123.
R=5234.

def test():
 print mine(phi0,w,t,w0,R)
 print theirs(phi0,w,t,w0,R)

test()
