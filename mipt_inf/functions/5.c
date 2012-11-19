#include <stdio.h>

#define N 20

void print(char a[N][N]);
void fill_rectangle(char a[N][N], int x, int y, int dx, int dy, char c);
void draw_rectangle(char a[N][N], int x, int y, int dx, int dy, char c);

void fill_rectangle(char a[N][N], int x, int y, int dx, int dy, char c)
{
    int cx, cy;
    for(cx = x; cx < x + dx; cx++)
        for(cy = y; cy < y + dy; cy++)
            a[cx][cy] = c;
}

void draw_rectangle(char a[N][N], int x, int y, int dx, int dy, char c)
{
    int cx, cy;
    for(cx = x; cx < x + dx; cx++)
        for(cy = y; cy < y + dy; cy++)
        {
            if((cy == y) || (cy == y + dy - 1) || (cx == x) || (cx == x + dx - 1))
                a[cx][cy] = c;
        }
}

void print(char a[N][N])
{
    int x, y;
    for(x = 0; x < N; x++)
    {
        for(y = 0; y < N; y++)
            printf("%c", a[y][x]);
        printf("\n");
    }
}

int main()
{
    char arr[N][N];
    fill_rectangle(arr, 0, 0, 10, 10, 'z');
    fill_rectangle(arr, 10, 0, 10, 10, '#');
    fill_rectangle(arr, 0, 10, 10, 10, '/');
    fill_rectangle(arr, 10, 10, 10, 10, '\\');
    draw_rectangle(arr, 2, 1, 13, 12, '@');
    draw_rectangle(arr, 7, 5, 11, 13, '=');
    print(arr);
    return 0;
}
