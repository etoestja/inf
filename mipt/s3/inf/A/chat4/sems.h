#ifndef SEMS_H
#define SEMS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/sem.h>
#include <fcntl.h>

#define PATHNAME "server.c"
#define NSEMS 2

//           m for 0  m for 1 mutex N-msgs
//              0       0       1     N
enum _SEMS {MUTEX, FULL};

void initSMS();

#endif
