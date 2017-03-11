import re
import sys
content = sys.stdin.readlines()
content = map(lambda x:list(x.strip()), content)
#print(content)

lines = len(content)
columns = len(content[0])

res = [' '] * columns

for i in range(columns):
  for j in range(lines):
    if content[j][i] == "+":
      if i < columns - 1 and content[j][i + 1] == "-":
        res[i] = "["
      elif content[j][i - 1] == "-":
        res[i] = "]"

res = ' '.join(res).strip()
res = re.sub(' ', '', res)
print(len(res))
print(res)
