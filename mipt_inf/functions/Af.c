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
