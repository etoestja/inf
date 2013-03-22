size_t my_strlen(const char *s)
{
    int i = 0;
    while(*s++) i++;
    return(i);
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    int i;
    for(i = 0; i < n; i++, *dest++ = *src++);
    return(dest);
}
