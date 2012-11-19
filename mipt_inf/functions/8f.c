void revers(char a[], int n)
{
    int i;
    char t;
    for(i = 0; i < n / 2; i++)
    {
        t = a[n - 1 - i];
        a[n - 1 - i] = a[i];
        a[i] = t;
    }
}

int my_strlen(char a[])
{
    int len;
    for(len = 0; a[len] == '1' || a[len] == '0'; len++);
    return(len);
}

void add(char a[], char b[], char res[])
{
    int aLen = my_strlen(a);
    int bLen = my_strlen(b);
    int i;

//    printf("alen = %d, blen = %d, a = %s, b = %s [done]\n", aLen, bLen, a, b);

    revers(a, aLen);
    revers(b, bLen);

    int sC, pos, carry = 0;
    for(pos = 0; pos < aLen || pos < bLen || carry != 0; pos++)
    {
        sC = carry;
        if(pos < aLen)
            sC += a[pos] - '0';
        if(pos < bLen)
            sC += b[pos] - '0';
        res[pos] = (sC % 2) + '0';
        carry = sC / 2;
    }

    res[pos] = 0;

//    printf("arev = %s, brev = %s, res = %s [done]\n", a, b, res);

    int resLen = my_strlen(res);
    revers(res, resLen);
    revers(a, aLen);
    revers(b, bLen);
}
