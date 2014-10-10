#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    int N;
    double a, b;
    vector<double> x, y, dx, dy;
    cin >> N;
    cin >> a >> b;

    // y = a * x + b

    double chi2 = 0;
    x.resize(N);
    y.resize(N);
    dx.resize(N);
    dy.resize(N);

    for(unsigned i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> dx[i] >> dy[i];
        chi2 += pow((a * x[i] + b - y[i]) / dy[i], 2);
    }

    cout << "chi2=" << chi2 << endl;

    return(0);
}
