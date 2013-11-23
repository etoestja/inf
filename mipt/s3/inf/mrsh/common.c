#include "myaes.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

void* decryptMessageCheckHash(char* ciphertext, int *len)
{
    unsigned char md5Digest1[MD5_DIGEST_LENGTH];

    //printf("decrypt called len=%d\n", *len);

    void* plain = AESDecrypt(ciphertext, len);

    unsigned char* md5Digest0 = (char*) (plain);
    char* message = md5Digest0 + MD5_DIGEST_LENGTH;

    if(*len <= 0 || plain == NULL)
    {
        fprintf(stderr, "Error decoding!\n");
        if(plain != NULL)
            free(plain);
        return(NULL);
    }
    else if((*len) >= (MD5_DIGEST_LENGTH + sizeof(char)))
    {
        MD5(message, (*len) - MD5_DIGEST_LENGTH, md5Digest1);

        int i;
//        printf("got digest ");
//        for(i = 0; i < MD5_DIGEST_LENGTH; i++)
//            printf("%02x", md5Digest0[i]);
//        printf("\n my digest ");
//        for(i = 0; i < MD5_DIGEST_LENGTH; i++)
//            printf("%02x", md5Digest1[i]);
//        printf("\n");

        for(i = 0; i < MD5_DIGEST_LENGTH; i++)
        {
            if(md5Digest0[i] != md5Digest1[i])
            {
                fprintf(stderr, "Wrong hash!\n");
                break;
            }
        }

        if(i == MD5_DIGEST_LENGTH)
            return(plain);
    }
    else
    {
        free(plain);
        return(NULL);
    }
}
