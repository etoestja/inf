#ifndef INT_THREADED
#define INT_THREADED

enum _mode {MODE_SHARED, MODE_RET};

double integrate_threaded(int P, int n, int mode);

#endif
