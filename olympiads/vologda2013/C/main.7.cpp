#include <iostream>

using namespace std;

#define NB 1000
#define KMAX 50

unsigned cH(unsigned H)
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

unsigned cHB[NB];
unsigned

int main()
{
    for(int i = 0; i < NB; i++)
    {
        cHB[i] = cH(i);
    }
    cout << cH(100) << endl;

    scanf("%u", &KL)

    return 0;
}
