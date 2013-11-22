#ifndef MYAES_H
#define MYAES_H

#define KEY "HUIHUIHUI"

void* AESDecrypt(void* ciphertext, int *size);
void* AESEncrypt(void* plain, int *size);
int AESInit();

#endif
