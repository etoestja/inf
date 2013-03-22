
int power(int a, unsigned int b)
{
    if(b == 0) return(1);
    else if(b == 1) return(a);
    else if(b % 2 == 0)
    {
        int c = power(a, b / 2);
        return(c * c);
    }
    else
        return(a * power(a, b - 1));
}

int my_strlen(char a[])
{
    int len;
    for(len = 0; (a[len] == '-') || (a[len] >= '0' && a[len] <= '9'); len++);
    return(len);
}

int my_atoi(char a[])
{
    int sign = 1;
    int value = 0;

    int ptr = 0;

    if(a[ptr] == '-')
    {
        sign = -1;
        ptr++;
    }

    int pow10;

    for(pow10 = my_strlen(a) - 1 - ptr; a[ptr] >= '0' && a[ptr] <= '9'; ptr++, pow10--)
        value += power(10, pow10) * (a[ptr] - '0');

    return(value * sign);
}
