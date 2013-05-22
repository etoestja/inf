#include <iostream>

using namespace std;

#define NB 1000

unsigned isH(unsigned H)
{
    unsigned res = 0, L = 0, N, c1, c2;
    for(L = 0; L < 1000; L++)
    {
        c1 = 0;
        c2 = 0;
        N = L + 1000 * H;
        c1 += N % 10;
        N /= 10;
        c2 += N % 10;
        N /= 10;
        c1 += N % 10;
        N /= 10;
        c2 += N % 10;
        N /= 10;
        c1 += N % 10;
        N /= 10;
        c2 += N % 10;
        N /= 10;
        if(c1 == c2)
        {
            res++;
            //cout << "isH: " << H << "\t" << L << "\t" << L + 1000 * H << endl;
        }
    }
    return(res);
}

bool isHB[NB];

int main()
{
    for(int i = 0; i < )
    cout << isH(100) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
