#ifndef INT_STDERR
#define INT_STDERR

void StdErr(const char* s, ...);
void StdErr_f(const char* s, ...);

#define INT_CERR

#ifdef INT_CERR
#define StdErr StdErr_f
#else
#define StdErr 
#endif

#endif
