h="It is a course on deep learning in natural language processing at MIPT".lower().split()
r="This is a course of deep learning in the processing of natural language in MIPT".lower().split()

n = N = 0
for w in h:
    if w in r:
        n += 1
    N += 1

print 1. * n / N
