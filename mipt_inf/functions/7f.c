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
