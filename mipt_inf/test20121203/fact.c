unsigned int fact(unsigned int n)
{
    unsigned int r = 1, i;
    for(i = 2; i <= n; i++)
        r *= i;
    return(r);
}
