#include <string.h>
#include <stdio.h>
#include <assert.h>

#define MAXN 105
#define SZ 1000

char s[MAXN];
char res[SZ][SZ];

int N;

int depth[MAXN];
int end_pos[MAXN];
int length_to_end[MAXN];
int length_full[MAXN];

int maxD = 0;

/* S -> SS (1)
 * S -> eps (2)
 * S -> [] (3)
 * S -> [S] (4)
 */

int parse_one(int idx, int d);
int parse_all(int idx, int d);

// case (1)
int parse_all(int idx, int d)
{
    int initial_idx = idx;
    int out = idx;
    while(true)
    {
        int tmp = parse_one(idx, d);
        length_full[initial_idx] += length_to_end[idx];
        if(tmp == -1)
            break;
        out = tmp;
        idx = tmp + 1;
    }
    return(out);
}

int parse_one(int idx, int d = 0)
{
    //printf("Parse One %d-? @ %d start: %c\n", idx, d, s[idx]);
    int res = idx;

    // case (2)
    if(idx == N)
        return(res);

    if((s[idx] != '[') || (idx == N - 1) || (idx == N))
        return(-1);

    // case(3)
    if(s[idx + 1] == ']')
    {
        depth[idx] = d;
        depth[idx + 1] = d;
        length_to_end[idx] = 5;
        res = idx + 1;
    }
    else // case (4)
    {
        res = parse_all(idx + 1, d + 1) + 1;
        assert(s[res] == ']');
        depth[idx] = d;
        depth[res] = d;
        length_to_end[idx] = 2 + length_full[idx + 1];
    }
    //printf("Parse One %d-%d @ %d end: %c\n", idx, res, d, s[res]);
    end_pos[idx] = res;

    return(res);
}

void print_arr(int* arr, const char* name)
{
    printf("%s\t", name);
    for(int i = 0; i < N; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int draw_bracket(int i, int x_min)
{
    assert(s[i] == '[');
    int h = 3 + 2 * (maxD - depth[i]);
    int H = 3 + 2 * maxD;
    int x_max = x_min + length_to_end[i] - 1;
    int top = (H - h) / 2;
    int bot = H - 1 - top;
    res[top][x_min] = '+';
    res[bot][x_min] = '+';
    res[top][x_max] = '+';
    res[bot][x_max] = '+';
    for(int i = top + 1; i < bot; i++)
    {
        res[i][x_min] = '|';
        res[i][x_max] = '|';
    }
    res[top][x_min + 1] = '-';
    res[bot][x_min + 1] = '-';
    res[top][x_max - 1] = '-';
    res[bot][x_max - 1] = '-';
    return(x_max);
}

int paint_one(int idx, int x_start);

int paint_all(int idx, int x_start)
{
    int x_max;
    while(true)
    {
        x_max = paint_one(idx, x_start);
        if(s[end_pos[idx] + 1] != '[')
            break;
        x_start = x_max + 1;
        idx = end_pos[idx] + 1;
    }
    return(x_max);

}

int paint_one(int idx, int x_start)
{
    int x_max = draw_bracket(idx, x_start);
    if(s[idx + 1] != ']')
    {
        paint_all(idx + 1, x_start + 1);
    }
    //printf("PaintOne %d %d-%d\n", idx, x_start, x_max);
    return(x_max);
}

int main()
{
    scanf("%d", &N);
    scanf("%s", s);

    memset(depth, 0x00, sizeof(depth));
    memset(end_pos, 0x00, sizeof(end_pos));
    memset(res, 0x20, sizeof(res));
    memset(length_to_end, 0x00, sizeof(length_to_end));
    memset(length_full, 0x00, sizeof(length_full));

    parse_all(0, 0);

    for(int i = 0; i < N; i++)
        if(depth[i] > maxD)
            maxD = depth[i];

    /*printf("%s\n", s);
    printf("Idx\t");
    for(int i = 0; i < N; i++)
        printf("%d\t", i);
    printf("\n");

    print_arr(depth, "depth");
    print_arr(length_to_end, "LTE");
    print_arr(length_full, "LF");

    printf("Input\t");
    for(int i = 0; i < N; i++)
        printf("%c\t", s[i]);

    printf("\n");*/

    paint_all(0, 0);

    for(int i = 0; i < 3 + 2 * maxD; i++)
    {
        for(int j = 0; j < length_full[0]; j++)
            printf("%c", res[i][j]);
        printf("\n");
    }

    return(0);
}
