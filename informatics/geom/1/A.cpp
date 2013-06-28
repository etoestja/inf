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

coord A, B, C;

void input()
{
    A.input();
    B.input();
    C.input();
}

int main()
{
    input();
    A -= C;
    B -= C;
    double r = fabs(A ^ B) / 2;
    cout.precision(10);
    cout << r << endl;
    return 0;
}
