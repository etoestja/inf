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
    double sigma_random;
    cin >> N >> sigma_random;

    vector<double> arr;
    arr.resize(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    double x = 0;

    for(int i = 0; i < N; i++)
        x += arr[i];

    x /= N;

    double S = 0;

    for(int i = 0; i < N; i++)
        S += pow(arr[i] - x, 2);

    double sigma_avg = sqrt(S / N / (N - 1));

    cout << "x_avg = " << x << endl;
    cout << "sigma_x_avg = " << sigma_avg << endl;
    cout << "sigma_total = " << sqrt(pow(sigma_random, 2) + pow(sigma_avg, 2)) << endl;

    return(0);
}
