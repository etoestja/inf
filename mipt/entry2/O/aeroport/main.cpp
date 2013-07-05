#include <iostream>
#include <vector>

using namespace std;

typedef pair<double, double> tCoord;

vector<tCoord> aero;
tCoord me;
unsigned int N;
double R;

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

    min += 60. * sec;
    deg += 60. * min;

    char c = " ";
    while(charSign(c) == 0)
        cin >> c;
    deg *= charSign(c);
    return(deg);
}

tCoord inputCoord()
{
    tCoord res;
    res.first = inputCoord1();
    res.second = inputCoord1();
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

}

int main()
{
    input();
    return(0);
}
