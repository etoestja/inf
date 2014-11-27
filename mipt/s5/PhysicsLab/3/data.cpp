#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#define a04 14704.5
#define a14 -1960.51
#define a24 4469.79
#define a34 2036.38

#define If 74.2

#define dT 20
#define epsdT 1e-5

#define m4 23035.1
#define sm4 50

using std::string;
using std::cout;
using std::cin;
using std::endl;

using std::stringstream;

double get_sI(double I)
{
    return(sqrt(I / dT + pow(I * epsdT, 2)));
}

double get_v_4()
{
    return((sqrt(pow(a24, 2) - 3 * a14 * a34) - a24) / 3. / a34);
}

double get_sv_4()
{
    return(0.1);
}

double get_I_4(double v)
{
    return(a04 + a14 * v + a24 * v * v + a34 * v * v * v);
}

double get_Imin_4()
{
    return(get_I_4(get_v_4()));
}

double get_sImin_4()
{
    return(100);
}

double get_eps(double I, double I0)
{
    return((I0 - I) / (I0 - If));
}

double get_seps(double I, double I0, double sI01)
{
    double sI0 = sqrt(pow(get_sI(I0), 2) + pow(sI01, 2));
    double sI = get_sI(I);
    double sIf = get_sI(If);

    double res = 0;
    res += pow((I - If) / (I0 - If) / (I0 - If) * sI0, 2);
    res += pow(sI / (I0 - If) / (I0 - If) * sI, 2);
    res += pow((I0 - I) / (I0 - If) / (I0 - If) * sIf, 2);

    return(sqrt(res));
}

string print_s(double v, double sv)
{
    stringstream ss;
    ss << v << " +/- " << sv;
    return(ss.str());
}

void print_sn(string name, double v, double sv)
{
    cout << name << " = " << print_s(v, sv) << endl;
}

const double E0 = 23.8e3;
const double c = 3e8;

// 1
/*#define mc 27875.8
#define smc 8.264
const double cc[] = {64964.6, -32058.4, 6414.02};
const double scc[] = {551.6, 486.1, 106.5};*/

// 2
/*#define mc 13165.8
#define smc 5.625
const double cc[] = {44601, -27410.8, 5561.95};
const double scc[] = {132.9, 109.8, 22.5};*/

// 3
#define mc 6244.03
#define smc 2.679
const double cc[] = {15345.7, -8256.7, 1646.78};
const double scc[] = {1147, 944.5, 190.2};

double get_v()
{
    return(-cc[1] / 2 / cc[2]);
}

double get_sv()
{
    double res = 0;
    res += pow(scc[1] / 2 / cc[2], 2);
    res += pow(cc[1] * scc[2] / 4 / cc[2] / cc[2], 2);
    return(sqrt(res));
}

double get_I(double v)
{
    return(cc[0] + cc[1] * v + cc[2] * v * v);
}

double get_sI(double v, double sv)
{
    double res = 0;

    res += pow(scc[0], 2);
    res += pow(v * scc[1], 2);
    res += pow(v * v * scc[2], 2);

    res += pow(sv * (cc[1] + 2 * cc[2] * v), 2);

    return(sqrt(res));
}

double get_Imin()
{
    return(get_I(get_v()));
}

double get_sImin()
{
    return(get_sI(get_v(), get_sv()));
}

double get_G()
{
    double res = 0;
    double I = get_Imin();

    res += pow(cc[1] / cc[2], 2);
    res -= 4 / cc[2] * (cc[0] - (mc + I) / 2);

    return(sqrt(res));
}

double get_sG()
{
    double res = 0;
    double I = get_Imin();
    double sI = get_sImin();

    double mu = pow(cc[1], 2) + 2 * cc[2] * (mc + I - 2 * cc[0]);

    res += pow(scc[0], 2) * 4 / mu;
    res += pow(scc[1], 2) * pow(cc[1] / cc[2], 2) / mu;
    res += pow(scc[2], 2) / mu / pow(cc[2], 4) * (pow(cc[1], 2) + cc[2] * (mc + I - 2 * cc[0]));
    res += (pow(smc, 2) + pow(sI, 2)) / mu;

    return(sqrt(res));
}

double get_E(double v)
{
    return(E0 * v / c);
}

int main()
{
/*    print_sn("v", get_v_4(), get_sv_4());
    print_sn("I", get_Imin_4(), get_sImin_4());
    print_sn("eps", get_eps(get_Imin_4(), m4), get_seps(get_Imin_4(), m4, sm4));*/

    print_sn("v, mm/s", get_v(), get_sv());
    print_sn("I, 1/s", get_Imin(), get_sImin());
    print_sn("eps", get_eps(get_Imin(), mc), get_seps(get_Imin(), mc, smc));
    print_sn("m, 1/s", mc, smc);
    print_sn("G, mm/s", get_G(), get_sG());
    print_sn("G, eV", get_E(get_G()), get_E(get_sG()));

}
