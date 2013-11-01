// initialization
void initWasher();
void initCleaner();
void initCommon();

//#define USE_SECONDS

// checks if table has space and puts one dish
int washSend(int i, int doWash);

// checks if table has washed dishes and takes one
int receiveClean();

void clean(int i, int time)
{
#ifdef USE_SECONDS
    fprintf(stderr, "Cleaning dish %d (%d seconds)... ", i, time);
    sleep(time);
#else
    fprintf(stderr, "Cleaning dish %d (%lf seconds)... ", i, time / 1E6);
    usleep(time);
#endif
    fprintf(stderr, "OK\n");
}

void wash(int i, int time)
{
#ifdef USE_SECONDS
    fprintf(stderr, "Washing dish %d (%d seconds)... ", i, time);
    sleep(time);
#else
    fprintf(stderr, "Washing dish %d (%lf seconds)... ", i, time / 1E6);
    usleep(time);
#endif
    fprintf(stderr, "OK\n");
}

void cleanedAll()
{
    fprintf(stderr, "Cleaned all (rcv msg)\n");
    exit(0);
}

void washedAll()
{
    fprintf(stderr, "Washed all\n");
    exit(0);
}
