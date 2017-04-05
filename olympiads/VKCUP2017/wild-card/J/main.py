import sys
import re
[n, k] = map(int, sys.stdin.readline().split())
seq = sys.stdin.readline().split()[0]

#print n, k, seq

def max_N(s):
    r = 0
    max_r = 0
    for i in range(len(s)):
        if s[i] == 'N':
            r += 1
        else:
            r = 0
        if r > max_r:
            max_r = r
    return max_r

def is_possible(s, k):
    s1 = "Y" + s + "Y"
    seq_N = s1.replace("?", "N")
    for i in range(len(seq_N)):
        if seq_N[i:i + k] == 'N' * k:
            if (s1[i - 1] in ["Y", "?"]) and (s1[i + k] in ["Y", "?"]):
                return 1
    return 0

seq_Y = seq.replace("?", "Y")
max_N_Y = max_N(seq_Y)

if max_N_Y > k:
    print("NO")
elif max_N_Y == k:
    print("YES")
else:
    if is_possible(seq, k):
        print("YES")
    else:
        print("NO")
