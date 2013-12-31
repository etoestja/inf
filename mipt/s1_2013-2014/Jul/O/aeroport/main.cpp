#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//#define DEBUG
#undef DEBUG

#define degToRad(x) (x * M_PI / 180.)

typedef pair<double, double> tCoord;
class vect
{
public:
    double x;
    double y;
    double z;
    vect()
    {
        x = 1;
        y = 0;
        z = 0;
    }
    vect(tCoord a)
    {
        x = 1;
        y = 0;
        z = 0;
#ifdef DEBUG
        cerr << a.first << " " << a.second << endl;
#endif
        rotateY(degToRad(a.second));
        rotateZ(degToRad(a.first));
//        rotateY(degToRad(a.first));
    }
    void rotateY(double rad)
    {
        // || cos 0 sin ||
        // ||  0  1  0  ||
        // ||-sin 0 cos ||
        vect old = *this;
        x = cos(rad) * old.x + sin(rad) * old.z;
        y =                old.y;
        z = -sin(rad)* old.x + cos(rad) * old.z;
    }
    void rotateZ(double rad)
    {
        // || cos -sin 0||
        // || sin cos 0 ||
        // ||  0   0  1 ||
        vect old = *this;
        x = cos(rad) * old.x - sin(rad) * old.y;
        y = sin(rad) * old.x + cos(rad) * old.y;
        z =                               old.z;
    }
    void print()
    {
        cout << x << " " << y << " " << z << endl;
    }
    double operator*(vect b)
    {
        return(x * b.x + y * b.y + z * b.z);
    }
    double len()
    {
        return(sqrt((*this) * (*this)));
    }
    double operator^(vect b)
    {
        return(acos(((*this) * b) / (len() * b.len())));
    };
};

vector<tCoord> aero;
tCoord me;
unsigned int N;
double R;
double dMin = 10;

void updateMin(double x)
{
    if(dMin > x) {dMin = x;}
}

int charSign(char t)
{
    if(t == 'w')
        return(-1);
    else if(t == 'e')
        return( 1);
    else if(t == 'n')
        return( 1);
    else if(t == 's')
        return(-1);
    return(0);
}

double inputCoord1()
{
    double deg;
    double min;
    double sec;
    cin >> deg >> min >> sec;

    sec *= 1. / 60;
    min += sec;
    min *= 1. / 60;
    deg += min;

    char c = ' ';
    while(charSign(c) == 0)
        cin >> c;
    deg *= charSign(c);
//    cerr << "deg=" << deg << endl;
    return(deg);
}

tCoord inputCoord()
{
    tCoord res;
    res.first = inputCoord1();
    res.second = inputCoord1();
    return(res);
}

void output()
{
    cout.precision(100);
    cout << R * dMin << endl;
}

void input()
{
    cin >> R;
    me = inputCoord();
    cin >> N;

    tCoord myTCoord;
    for(unsigned i = 0; i < N; i++)
    {
        myTCoord = inputCoord();
        aero.push_back(myTCoord);
    }
}



double distanceCoord(tCoord c1, tCoord c2)
{
    vect v1(c1), v2(c2);
#ifdef DEBUG
    v1.print();
    v2.print();
    cerr << "dist=" << (v1 ^ v2) << endl;
#endif
    return(v1 ^ v2);
}

void calcMin()
{
    for(unsigned i = 0; i < N; i++)
        updateMin(distanceCoord(me, aero[i]));
}

int main()
{
    input();
    calcMin();
    output();
    return(0);
}
