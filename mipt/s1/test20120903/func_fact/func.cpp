unsigned int fact(unsigned int n)
{
    return(n ? n * fact(n - 1) : 1);
}
