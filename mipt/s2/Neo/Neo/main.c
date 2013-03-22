//#define DEBUG 1
#undef DEBUG

#ifdef DEBUG
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    struct anomaly
    {
        char name_of_anomaly[256];
        int number_of_anomaly;
    };

    void print_anomaly(struct anomaly a)
    {
        printf("name (%d) = %s\n", strlen(a.name_of_anomaly), a.name_of_anomaly);
        printf("number = %d\n", a.number_of_anomaly);
    }

    void copy(struct anomaly *a, char* s)
    {
        int i;
        for(i = 0; s[i] != 0; i++)
            a->name_of_anomaly[i] = s[i];
        a->name_of_anomaly[i] = 0;
    }

#endif

char* whatisyourname()
{
    const unsigned int N = 256 + 1;
    char* s = malloc(N * sizeof(char));
    int i;
    for(i = 0; i < 256; i++)
        s[i] = '0';
    s[256] = 0;
    
    return(s);
}

#ifdef DEBUG
    int main()
    {
        struct anomaly a;
        a.number_of_anomaly = 6;
        copy(&a, whatisyourname());
        print_anomaly(a);
    
        return(0);
    }
#endif
