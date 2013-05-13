long double Ryad(int N)
{
    long double r = 0, t;
    int i;
    for(i = N; i >= 1; i--)
//    for(i = 1; i <= N; i++)
    {
        t = (long double) i;
        r += ((long double) 1.) / (t * (t + 2));
    }

    return(r);
}
