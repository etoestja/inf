#include <iostream>

using namespace std;

int main()
{
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout.precision(100);

    cout << (x1 + x2 + x3) / 3 << " " << (y1 + y2 + y3) / 3 << endl;

    return(0);
}
