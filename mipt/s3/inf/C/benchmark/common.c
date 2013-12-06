#include "common.h"

extern struct timeb oldTime;

void setTime()
{
	ftime(&oldTime);
}

unsigned long long getTime(struct timeb *a)
{
	return(a->time * 1000 + a->millitm);
}

unsigned long long getTimeDifference()
{
	struct timeb newTime;
	ftime(&newTime);

	unsigned long long res = getTime(&newTime) - getTime(&oldTime);

	return(res);
}
