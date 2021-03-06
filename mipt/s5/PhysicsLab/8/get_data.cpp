#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

#define N 4

const long double c[N + 1] = {4382.79, -1.61777, 0.00224345, -9.55523e-07, 1.63633e-10};
const long double s[N + 1] = {76.32, 0.2127, 0.0001969, 7.422e-08, 9.842e-12};

const long double c_v_light = 299792458.;

long double la(long double x)
{
    long double res = 0;
    for(unsigned i = 0; i <= N; i++)
        res += pow(x, i) * c[i];
    return(res);
}

long double sla(long double B, long double sB)
{
    long double res = 0, a;

    for(unsigned i = 0; i <= N; i++)
    {
        a = pow(s[i], 2) * pow(B, 2 * i);

//        cout << "r" << i << "=" << a << endl;

        //res += a;
    }

    long double dladB = 0;
    for(unsigned i = 1; i <= N; i++)
        dladB += i * c[i] * pow(B, i - 1);

    long double rB = pow(dladB, 2) * pow(sB, 2);

//    cout << "rB=" << rB << endl;

    res += rB;

    return(sqrt(res));
}

void console()
{
    long double B, sB;
    while(true)
    {
        cout << "B= > ";
        cin >> B;

        cout << "sB= > ";
        cin >> sB;
        cout << "La(A) = " << la(B) << " +- " << sla(B, sB) << endl;
    }
}

void in()
{
    long double B, sB;
    int K;
    cin >> K;
    for(unsigned i = 0; i < K; i++)
    {
        cin >> B >> sB;
        long double la_ = la(B);
        long double sla_ = sla(B, sB);
        long double nu_ = c_v_light / la_;
        long double snu_ = nu_ * sla_ / la_;
        cout << B << "\t" << sB << "\t" << la_ << "\t" << sla_ << "\t" << nu_ << "\t" << snu_ << endl;
    }
}

int main()
{
    //console();
    in();

    return(0);
}
