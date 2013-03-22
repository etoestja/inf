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

int my_strcmp(const char *s1, const char *s2)
{
    for(; (*s1) && (*s2) && ((*s1) == (*s2)); s1++, s2++);

    if(*s1 < *s2) return(-1);
    else if(*s1 > *s2) return(1);
    else return(0);
}

char* my_strchr(const char *s, int c)
{
    for(; *s; s++) if(*s == c) return(s);
    return(NULL);
}
