import matplotlib.pyplot as plt
import math
import string
import random
#target = "METHINKS IT IS LIKE A WEASEL"
#target = "ABA"
target = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec malesuada enim non ante tempus, sed consequat nibh mattis"

lett = string.letters + ' ' + '.' + ','
thresold = 0.99
N = 100
best = None
gen = 0

def get_random_string(length):
    s = ""
    for i in range(length):
        s += random.choice(lett)
    return(s)

def difference(s1, s2):
    s = 0
    for i in range(len(s1)):
        s += int(s1[i] != s2[i])
    return(s)

def fitness(s):
    return(-difference(s, target))

def mutate(s):
    l = list(s)
    for i in range(len(s)):
        if random.random() > thresold:
            l[i] = random.choice(lett)
    return(''.join(l))

def get_best(pop):
    maxf = -2 * len(target)
    r = None
    for f in pop:
        if fitness(f) > maxf:
            maxf = fitness(f)
            r = f
    return(r)

def iteration():
    pop = []
    global best, gen
    for i in range(N):
        pop.append(mutate(best))
    best = get_best(pop)
    gen += 1

best = get_random_string(len(target))
fitness_exp = 0
alpha = 0.1

def print_best():
    print("GENERATION {} BEST <{}> FITNESS {} EXP {} THRESOLD {}".format(gen, best, fitness(best), fitness_exp, int(thresold * 100)))

def sigma(x):
    return(1 / (1 + math.exp(-x)))

fitnesses = []
fitness_exp = fitness(best)
print_best()
while fitness(best) < 0:
    fitnesses.append(fitness(best))
    fitness_exp = fitness(best) * alpha + fitness_exp * (1 - alpha)
#    thresold = alpha * sigma(fitness_exp - fitness(best)) + thresold * (1 - alpha)
    iteration()
    print_best()

plt.plot(fitnesses)
plt.savefig('evolution.png')
