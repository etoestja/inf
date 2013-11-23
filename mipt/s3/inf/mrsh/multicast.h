#ifndef MULTICAST_H
#define MULTICAST_H

#define GROUPADDR "225.1.1.1"
#define PORT 5555

void multicastInit(char* ifaceAddr);
//void multicastInitTx(char* ifaceAddr);

int multicastRx(void *buf, size_t len);
int multicastTx(const void* buf, size_t len);

#endif // MULTICAST_H
