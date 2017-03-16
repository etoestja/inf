import sys
import heapq

H = []

[n, k, q] = map(int, sys.stdin.readline().split())
T = [0] + map(int, sys.stdin.readline().split())

#print(n, k, q)
#print(T)

def in_k_max(idx):
    arr = []
    res = 0
    while len(arr) < k and len(H) > 0:
        arr.append(heapq.heappop(H))
    for v in arr:
        if v[1] == idx:
            res = 1
        heapq.heappush(H, v)
#    print("Queried: " + str(idx) + " Arr: " + str(arr))
    return(res)

for i in range(q):
    [r_type, r_id] = map(int, sys.stdin.readline().split())
    if r_type == 1:
        heapq.heappush(H, (-T[r_id], r_id))
    if r_type == 2:
        s = "NO"
        if in_k_max(r_id):
            s = "YES"
        print(s)
#    print(H)
