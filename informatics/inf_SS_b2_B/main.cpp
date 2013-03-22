#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

using std::cerr;

using std::string;
using std::stringstream;

const int M_ = 1400;
int v, d, N, times[M_], x[M_];

void input_hhmm(int& x)
{
    int t1, t2;
    char c;

    cin >> t1 >> c >> t2;

    x = t1 * 60 + t2;
}

string print_lead(int x)
{
    stringstream ss;

    if(x <= 9) ss << "0";
    ss << x;

    return(ss.str());
}

string print_hhmm(int x)
{
    stringstream ss;

    ss << print_lead(x / 60) << ":"
       << print_lead(x % 60);

    return(ss.str());
}

string print_hhmm_cm(int x)
{
    int min = x / v;

    if(min * v < x) min++;

    return(print_hhmm(min));
}

string print_hhmm_sec(int x)
{
    stringstream ss;
    float sec = 60. * (((float)x / v) - x / v);
    ss << print_hhmm(x / v) << ":" << sec;
    return(ss.str());
}

bool available(int left, int m, int i)
{
    return((N - left) * d + m + x[i] >= times[i]);
}

int get_left(int m)
{
    int left = N, i;

    for(i = 0; i + 1 < N; i++)
        if(available(left, m, i)) left--;

    return(left);
}

int main()
{
    int i, l = 0, r = 24 * 60 - 1, m;

    cin >> v >> d >> N;
    r *= v;
    m = (l + r) / 2;
    d *= v;


    for(i = 0; i < N; i++)
    {
        cin >> x[i];
        input_hhmm(times[i]);
        times[i] *= v;
    }

    if(N == 0)
    {
        cout << print_hhmm(0) << endl;
        return 0;
    }

    while(l != m && r != m)
    {
        //cerr << "trying " << (float)m << " " << print_hhmm_sec(m) << " [" << print_hhmm_sec(l) << ", " << print_hhmm_sec(r) << "]" << endl;
        if(available(get_left(m), m, N - 1))
            r = m;
        else l = m;

        m = (l + r) / 2;
    }

    cerr << "l=" << print_hhmm_cm(l) << " r=" << print_hhmm_cm(r) << endl;

    m = r;
    if(available(get_left(l), l, N - 1)) m = l;
    else cerr << "l not av." << endl;

    cerr << "leaving at " << print_hhmm_sec(m) << endl
         << "@" << N << " time=" << print_hhmm_sec(m + (N - get_left(m)) * d + x[N - 1]) << endl;

    cout << print_hhmm_cm(m + N * d + 2 * x[N - 1]) << endl;

    return 0;
}
