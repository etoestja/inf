int erase;

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                          (Linux-specific) */
};

int semid;
key_t key;

void getKey()
{
    key = ftok(PATHNAME, 0);
}

void getSemID()
{
    semsInitial[FULL] = N;
    //printf("initial2=%d\n", semsInitial[2]);
    getKey();
    if((semid = semget(key, NSEMS, 0666 | IPC_CREAT | IPC_EXCL)) < 0)
    {
        if(errno == EEXIST)
        {
            if((semid = semget(key, NSEMS, 0666 | IPC_CREAT)) < 0)
            {
                printf("Can't create semaphore set II\n");
                exit(-1);
            }
        }
        else
        {
            printf("Can\'t create semaphore set I\n");
            exit(-1);
        }
    }
    if(erase)
    {
        //created OK
        int i;
        union semun semopts;

        for(i = 0; i < NSEMS; i++)
        {
            semopts.val = semsInitial[i];
            if(semctl(semid, i, SETVAL, semopts) < 0)
            {
                fprintf(stderr, "Can't semctl!\n");
                exit(-1);
            }
        }
    }
}
