#include <stdio.h>

#define M (1024 + 1)
#define ROWS 2

unsigned long long arr[ROWS][M], res = 0;

unsigned current_row;

unsigned n, k;

void read();
void solve();
void write();

void current_row_update()
{
    if(current_row >= ROWS - 1) current_row = 0;
    else current_row++;
}

unsigned get_prev_row()
{
    return(current_row == 1 ? 0 : 1);
}

unsigned long long get_value_prev(unsigned n, unsigned k)
{
    unsigned long long res = 0;
    if(k != 0) res += arr[get_prev_row()][k - 1];
    if(k <= n - 1) res += arr[get_prev_row()][k];

    return(res);
}

//405ГК

void read()
{
    scanf("%u", &n);
    scanf("%u", &k);
}

void solve()
{

    unsigned i, si;

    current_row = 0;
    arr[current_row][0] = 1;

    current_row_update();

    for(i = 1; i <= n; i++)
    {
        for(si = 0; si <= i; si++)
        {
            //printf("row = %d, n = %d, k = %d, i = %d, si = %d, adding %lld\n", current_row, n, k, i, si, get_value_prev(i, si));
            arr[current_row][si] = get_value_prev(i, si);
        }

        current_row_update();
    }

    current_row_update();
}

void write()
{
    printf("%lld\n", arr[current_row][k]);
}

int main()
{
    read();
    solve();
    write();

    return 0;
}
