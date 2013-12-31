#include <iostream>
#include <math.h>

using namespace std;

class coord
{
    public:
    double x;
    double y;
    void input()
    {
        cin >> x >> y;
    }

    coord operator-=(coord b)
    {
        x -= b.x;
        y -= b.y;
        return(*this);
    }

    coord operator-(coord b)
    {
        coord c = *this;
        c -= b;
        return(c);
    }

    double operator^(coord b)
    {
        // || i j k ||
        // || a b 0 ||
        // || d e 0 ||
        return(x * b.y - y * b.x);
    }
};

#define NMAX 1005

coord arr[NMAX];
int N;

void input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        arr[i].input();
    for(int i = N - 1; i > 0; i--)
    {
        arr[i] -= arr[i - 1];
    }
}

int main()
{
    input();

    int s = 0;
    double t;
    for(int i = 2; i <= N - 1; i++)
    {
        t = arr[i] ^ arr[i - 1];
//        cout << "t=" << t << endl;
        if(t < 0) s++;
    }

    cout << s << endl;

    return 0;
}
