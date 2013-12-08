#include <stdio.h>

//#define DEBUG

enum _state{READING_TEXT = 1, READING_SPACES};

int main()
{
    int c;

    int state = READING_TEXT, oldState = READING_TEXT;

#ifdef DEBUG
    printf("[");
#endif

    while((c = fgetc(stdin)) != EOF)
    {
        if(c == ' ') state = READING_SPACES;
        else state = READING_TEXT;

        if(state == READING_SPACES && oldState == READING_TEXT)
            printf(" ");
        else if(state == READING_TEXT)
            printf("%c", (char) c);

//        fprintf(stderr, "got [%c]\n", (char) c);

        oldState = state;
    }

#ifdef DEBUG
    printf("]");
#endif

    return(0);
}
