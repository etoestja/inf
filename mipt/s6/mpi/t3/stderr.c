#include "stderr.h"
#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <sys/types.h>

void StdErr_f(const char* s, ...)
{
    va_list args;
    va_start(args, s);
    const unsigned EXCEPTION_BUFSIZE = 2048;
    char buf[EXCEPTION_BUFSIZE];

    pid_t tid;
    tid = syscall(SYS_gettid);
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned n = sprintf(buf, "INT %ld.%06ld TID %d\t", tv.tv_sec, tv.tv_usec, tid);

    vsnprintf(buf + n, EXCEPTION_BUFSIZE - n - 1, s, args);
    buf[EXCEPTION_BUFSIZE - 1] = 0;
    va_end(args);
    fprintf(stderr, "%s\n", buf);
}
