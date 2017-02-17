from random import shuffle
arr = range(0, 10)
shuffle(arr)

def merge_sort(arr):
    q = len(arr)
    if q == 1:
        return arr
    m = q / 2
    l = merge_sort(arr[:m])
    r = merge_sort(arr[m:])
    i = 0
    j = 0
    res = []
    while i < len(l) or j < len(r):
        la = 0
        if j >= len(r):
            res.append(l[i])
            i += 1
            continue
        elif i >= len(l):
            res.append(r[j])
            j += 1
            continue
        print("c")
        if l[i] < r[j]:
            res.append(l[i])
            i += 1
        else:
            res.append(r[j])
            j += 1
    return(res)

merge_sort(arr)
