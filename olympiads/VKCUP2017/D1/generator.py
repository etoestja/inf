from random import random as rr

def random_one(prob_down = 0.9, prob_stop = 0.1):
    res = ''
    while rr() >= prob_stop:
        res += '['
        if rr() <= prob_down:
            res += random_one(prob_down / 2, prob_stop * 2)
        res += ']'
    return(res)

while True:
    s = random_one(0.93, 0.05)
    if len(s) >= 2 and len(s) <= 100:
        print(len(s))
        print(s)
        break
