#ifndef MYAES_H
#define MYAES_H

#define KEY "MYSECRETKEY"

void* AESDecrypt(void* ciphertext, int *size);
void* AESEncrypt(void* plain, int *size);
int AESInit();

#endif
