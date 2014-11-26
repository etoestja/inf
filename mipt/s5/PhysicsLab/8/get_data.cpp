#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

#define NPOLY 4

const double c[N + 1] = {0, 0, 0, 0, 0}
const double s[N + 1] = {0, 0, 0, 0, 0};

double la(double x)
{
    double res = 0;
    for(unsigned i = 0; i <= N; i++)
        res += pow(x, i) * c[i];
}

double sla(double B, double sB)
{
    double res = 0, a;

    for(unsigned i = 0; i <= N; i++)
        res += pow(s[i], 2) * pow(B, 2 * i);

    double dladB = 0;
    for(unsigned i = 1; i <= N; i++)
        dladB += i * c[i] * pow(B, i - 1);

    double r5 = pow(dladB, 2) * pow(sB, 2);

    cout << "rB=" << r5 << endl;

    res += rB;

    return(sqrt(res));
}

int main()
{
    double B, sB;
    while(true)
    {
        cout << "B= > ";
        cin >> B;

        cout << "sB= > ";
        cin >> sB;
        cout << "La(A) = " << la(B) << " +- " << sla(B, sB) << endl;
    }

    return(0);
}
