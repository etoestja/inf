import sys
from string import split

N = int(raw_input())
arr = map(int, split(raw_input()))

likes = {}

i = 0
for a in arr:
    if likes.get(a) == None:
        likes[a] = (1, -i)
    else:
        likes[a] = (likes[a][0] + 1, -i)
    i += 1

res = []

for id in likes:
    res.append((likes[id][0],likes[id][1],id))

res = sorted(res)
res.reverse()

print(res[0][2])

#print(likes)
#print(res)
