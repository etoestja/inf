#ifndef NICE_STDERR
#define NICE_STDERR

void StdErr(const char* s, ...);
void StdErr_f(const char* s, ...);

//#define NICE_CERR

#ifdef NICE_CERR
#define StdErr StdErr_f
#else
#define StdErr 
#endif

#endif
