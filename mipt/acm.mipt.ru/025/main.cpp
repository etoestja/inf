#include <iostream>
#include <stdio.h>
#include <math.h>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

//#define DEBUG
#undef DEBUG

class coord
{
    public:
    double x;
    double y;
    void scan()
    {
        cin >> x >> y;
    }
    double operator&(coord b)
    {
        double z;
        z = x * b.x + y * b.y;
        return(z);
    }
    coord operator-(coord b)
    {
        coord z;
        z.x = x - b.x;
        z.y = y - b.y;
        return(z);
    }
    double len2()
    {
        return(*this & *this);
    }
    double len()
    {
        return(sqrt(len2()));
    }
    coord operator*(double a)
    {
        coord z;
        z.x = x * a;
        z.y = y * a;
        return(z);
    }
    void print()
    {
        cout << x << '\t' << y << endl;
    }
};

coord A, B, X1, X2;
double h1, h2, L;
coord a;

double tmin;

double g()
{
    return((B - A).len());
}

double f(double a, double b)
{
    return(sqrt(a * a + h1 * h1) + sqrt(b * b + h2 * h2) + (L - a - b) / M_SQRT2);
}

coord proj(coord x)
{
    return(X1 - a * (-1)*(((x - X1) & a) / a.len2()));
}

void init()
{
    a = X2 - X1;
    coord a1, b1;
    a1 = proj(A);
    b1 = proj(B);
    #ifdef DEBUG
        cout << "a1=";
        a1.print();
        cout << "b1=";
        b1.print();
    #endif
    L = (b1-a1).len();
    h1 = (A - a1).len();
    h2 = (B - b1).len();
}

void test_tmin(double a, double b)
{
    #ifdef DEBUG
        cerr << a << '\t' << b << '\t';
    #endif
    if(a + b > L)
    {
        #ifdef DEBUG
            cerr << "E" << endl;
        #endif
        return;
    }
    #ifdef DEBUG
        cerr << "OK, ";
    #endif
    double t = f(a, b);
    #ifdef DEBUG
        cerr << t << endl;
    #endif
    if(t < tmin) tmin = t;
}

void set_tmin()
{
    tmin = g();
    
    test_tmin(0, 0);
    test_tmin(0, L);
    test_tmin(0, h2);
    test_tmin(L, 0);
    test_tmin(h1, 0);
    test_tmin(h1, h2);
}

void print_tmin()
{
    #ifdef DEBUG
    cerr << "TMIN=" << tmin << endl;
    #endif
    printf("%.2lf\n", tmin / 5);
}

void debug()
{
    cout << "L=" << L << endl;
    cout << "h1=" << h1 << endl;
    cout << "h2=" << h2 << endl;
    cout << "A=";
    A.print();
    cout << "B=";
    B.print();
    cout << "X1=";
    X1.print();
    cout << "X2=";
    X2.print();
    cout << "a=";
    a.print();
}

int main()
{
    A.scan();
    B.scan();
    X1.scan();
    X2.scan();
    init();
    #ifdef DEBUG
        debug();
    #endif
    
    set_tmin();
    print_tmin();
    
    return(0);
}
