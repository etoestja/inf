#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int asc(int x)
{
    return(x * x);
}

int desc(int x)
{
    return(-x);
}

unsigned N, I;
int *arr;
#define INF ((2 << 31) - 1)

void fill()
{
    int i;
    for(i = 0; i < I; i++) arr[i] = asc(i);
    for(i = I; i < N; i++) arr[i] = desc(i);
}

int main()
{
    cin >> N;
    cin >> I;
    arr = new int[N];
    fill();

/*    for(int i = 0; i < N; i++) cout << i << "\t";
    cout << endl;
    for(int i = 0; i < N; i++) cout << arr[i] << "\t";
    cout << endl;*/

    int l = 0, r = N;
    int m1, m2;
    arr[N] = -INF;
    while(l + 2 < r)
    {
        m1 = (    r + 2 * l) / 3;
        m2 = (2 * r +     l) / 3;
//        cout << "l=" << l << " m1=" << m1 << " m2=" << m2 << " r=" << r << endl;

        if(arr[m1] < arr[m2])
            l = m1;
        else r = m2;

    }

    //arr[l], arr[r], arr[(l+r)/2]
/*    cout << "l=" << l << " arr[l]=" << arr[l] << endl;
    cout << "r=" << r << " arr[r]=" << arr[r] << endl;*/
    if(arr[l] < arr[l + 1]) l++;
    if(arr[l] < arr[l + 1]) l++;
//    cout << r << endl;

/*    int l, r, m;
    while(l + 1 < r)
    {
        m = (l + r) / 2;
    }*/

    return(0);
}
