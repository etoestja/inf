#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

#define VNUM 2
#define NNUM (VNUM + 1)

//#define DEBUG

#define MAXLEN 10000

typedef struct
{
    long double coeff[NNUM];
    int e_position;
} pa_t;

void print_pa_t(pa_t x)
{
    printf("%Lf+%Lf*x+%Lf*y, %d", x.coeff[0], x.coeff[1], x.coeff[2], x.e_position);
}

pa_t parse_eq_nosum(char* s, int s_position);
pa_t parse_eq(char* s, int s_position);

bool isSymNum(char c)
{
    return((c >= '0' && c <= '9') || c == '-');
}

pa_t parse_num(char* s, int s_position)
{
    stringstream ss;
    double t;
    int n;

    pa_t r;

    r.coeff[1] = 0;
    r.coeff[2] = 0;

    r.e_position = s_position;

    if(isSymNum(s[s_position]) && sscanf(s + s_position, "%lf%n", &t, &n) > 0)
    {
        r.coeff[0] = t;
        r.e_position = s_position + n;
    }
    else
    {
        if(s[s_position] == '-')
        {
            r.coeff[0] = -1;
            r.e_position = s_position + 1;
        }
        else
            r.coeff[0] = 0;
    }

    return(r);
}

pa_t parse_a_eq(char *s, int s_position)
{
    pa_t r1 = parse_num(s, s_position);

    if(r1.e_position > s_position)
    {
        // got int
        s_position = r1.e_position;
    }
    else
        r1.coeff[0] = 1;

    if(s[s_position] != 'x' && s[s_position] != 'y' && s[s_position] != '(')
        return(r1);

    bool bracket = false;

    if(s[s_position] == '(')
    {
        s_position++;
        bracket = true;
    }

    pa_t r2;
    if(bracket)
         r2 = parse_eq(s, s_position);
    else r2 = parse_eq_nosum(s, s_position);


    if(bracket)
        r2.e_position++;

    r2.coeff[0] *= r1.coeff[0];
    r2.coeff[1] *= r1.coeff[0];
    r2.coeff[2] *= r1.coeff[0];

    return(r2);
}

pa_t parse_xy(char* s, int s_position)
{
    pa_t r;

    r.e_position = s_position;
    r.coeff[0] = 0;
    r.coeff[1] = 0;
    r.coeff[2] = 0;

    if(s[s_position] == 'x')
    {
        r.coeff[1] = 1;
        r.e_position++;
    }
    else if(s[s_position] == 'y')
    {
        r.coeff[2] = 1;
        r.e_position++;
    }

    return(r);
}

pa_t parse_eq_nosum(char* s, int s_position)
{
    pa_t r;
    r = parse_xy(s, s_position);

    bool ok = false;

    if(r.e_position > s_position)
        ok = true;

    if(!ok)
        r = parse_a_eq(s, s_position);

#ifdef DEBUG
    if(r.e_position <= s_position)
        fprintf(stderr, "ERROR PARSE EQ NO TERM\n");
#endif

    return(r);
}

pa_t parse_eq(char* s, int s_position)
{
    pa_t r = parse_eq_nosum(s, s_position);

    if(s[r.e_position] == '+')
    {
        pa_t r1 = parse_eq(s, r.e_position + 1);
        r1.coeff[0] += r.coeff[0];
        r1.coeff[1] += r.coeff[1];
        r1.coeff[2] += r.coeff[2];

        return(r1);
    }
    else if(s[r.e_position] == '-')
    {
        pa_t r1 = parse_eq(s, r.e_position);
        r1.coeff[0] += r.coeff[0];
        r1.coeff[1] += r.coeff[1];
        r1.coeff[2] += r.coeff[2];

        return(r1);
    }
    else return(r);
    /*else
        fprintf(stderr, "ERROR PARSE EQ NO NEXT")*/
}

pa_t parse_eq2(char* s)
{
    pa_t r1 = parse_eq(s, 0);

#ifdef DEBUG
    if(s[r1.e_position] != '=')
        fprintf(stderr, "ERROR PARSING NO =\n");
#endif

    pa_t r2 = parse_eq(s, r1.e_position + 1);

    r1.coeff[0] -= r2.coeff[0];
    r1.coeff[1] -= r2.coeff[1];
    r1.coeff[2] -= r2.coeff[2];

    r1.e_position = r2.e_position;

#ifdef DEBUG
    if(r2.e_position != strlen(s))
    {
        fprintf(stderr, "ERROR PARTIAL PARSING\n");
    }
#endif

    return(r1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char s[MAXLEN];

    scanf("%s", s);
    pa_t x = parse_eq2(s);

    scanf("%s", s);
    pa_t y = parse_eq2(s);

#ifdef DEBUG
    print_pa_t(x);
    printf("\n");
    print_pa_t(y);
    printf("\n");
#endif

    long double a = -x.coeff[0];
    long double b = -y.coeff[0];

    long double a11 = x.coeff[1];
    long double a12 = x.coeff[2];

    long double a21 = y.coeff[1];
    long double a22 = y.coeff[2];

    long double Dx = a * a22 - b * a12;
    long double Dy = b * a11 - a * a21;

    long double D = a11 * a22 - a21 * a12;

#ifdef DEBUG
    printf("%Lf %Lf %Lf\n", Dx, Dy, D);
#endif

    long double xa = Dx;
    xa /= D;

    long double ya = Dy;
    ya /= D;

    cout.precision(10);
    cout << xa << " " << ya << endl;

    return 0;
}

