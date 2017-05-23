import os
from models.settings import *
from models.model import initialize_model
import numpy as np
import pandas as pd

# initialize model
model = initialize_model()
model.load_weights("model_params/weights-improvement-07-0.62.hdf5")

def get_data_from_file(file):
    data = pd.read_csv(file, index_col=0)
    return np.array(data.values.tolist())
    
input_files = os.listdir('data/test')

X = np.array(map(lambda x : get_data_from_file(TEST_DATA_DIR + x), input_files))
y = model.predict(X, batch_size = 32).argmax(axis = 1)

f = open('results.csv', 'w')
f.write('file,activity\n')
#for i in range(min(y, 10)):
for i in range(len(y)):
    f.write('{},{}\n'.format(input_files[i][:-4], y[i] + 1))
f.close()
