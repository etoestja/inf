a=1
b=1
c=1

i=1
print i,a+b+c

for i in range(1+1,2014+1):
    at=a
    bt=b
    ct=c

    a=at+bt
    b=at+bt+ct
    c=bt+ct
    print i,a+b+c
