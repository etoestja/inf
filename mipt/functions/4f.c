void draw_rectangle(int w, int h, char c)
{
    int i, si;

    for(i = 0; i < h; i++)
    {
        if(i == 0 || i + 1 == h)
        {
            for(si = 0; si < w; si++)
                printf("%c", c);
        }
        else
        {
            for(si = 0; si < w; si++)
            {
                printf("%c", (si == 0 || ((si + 1) == w)) ? c : ' ');
            }
        }
        printf("\n");
    }
}
