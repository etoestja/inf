import os
from random import sample
from tqdm import tqdm

to_validation = 0.1
classes = os.listdir('data/train')

print "Moving all objects to train"

for c in classes:
    files = os.listdir('data/validation/' + c)
    for f in tqdm(files):
        os.rename('data/validation/' + c + '/' + f, 'data/train/' + c + '/' + f)

print "Moving {}% objects to validation".format(to_validation * 100)

for c in classes:
    files = os.listdir('data/train/' + c)
    L = len(files)
    l = int(to_validation * L)
    v_files = sample(files, l)
    for v_file in tqdm(v_files):
        os.rename('data/train/' + c + '/' + v_file, 'data/validation/' + c + '/' + v_file)
