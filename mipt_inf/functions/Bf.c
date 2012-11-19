void fill_rectangle(int w, int h)
{
    int w0 = w;
    for(; h; h--)
    {
        for(w = w0; w; w--)
            printf("*");
        printf("\n");
    }
}
