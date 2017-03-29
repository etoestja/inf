
import numpy as np
try:
    import cPickle as pickle
except ImportError:
    import pickle

from multiprocessing import Pool

def mult_random_search(f, params_mean, params_std=1., n_workers=2, batch_size=100, n_iter=50):
    """ Multiprocessing version of Random Search algorithm."""
#    params_std = np.ones_like(params_mean) * params_std
    best_params = params_mean
    best_accuracy = 0
    pool = Pool(processes=n_workers)
    for _ in range(n_iter):
        params = params_std ** 0.5 * np.random.randn(*(params_mean.shape + (n_workers,))) + np.matlib.repmat(params_mean, n_workers, 1).T;
        # TO BE IMPLEMENTED: random search for parameters
        params_arr = map(lambda x : x[:, 0], np.split(params, n_workers, axis = -1))
        ys = np.array(pool.map(f, params_arr))
        if np.max(ys) > best_accuracy:
            best_params = params_arr[np.argmax(ys)]
            best_accuracy = np.max(ys)
        yield {'results' : ys, 'best_params' : best_params, 'best_accuracy' : best_accuracy}

def mult_cem(f, params_mean, params_std=1., n_workers=2, batch_size=100, n_iter=50, elite_frac=0.2):
    """ Multiprocessing version of CEM algorithm."""
    n_elite = int(np.round(batch_size * elite_frac))
    params_std = np.ones_like(params_mean) * params_std
    for _ in range(n_iter):
        pool = Pool(processes=n_workers)
        # TO BE IMPLEMENTED: CEM for search of parameters
        yield {'results' : ys, 'best_params' : best_params}

