#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

const unsigned int D = 10;
const unsigned int P = 10;

int arr[D][D] = {{0,0,0,0,0,0,0,0,0,0}, {0,1,2,3,4,5,6,7,8,9}, {0,2,4,6,8,10,12,14,16,18}, {0,3,6,9,12,15,18,21,24,27}, {0,4,8,12,16,20,24,28,32,36}, {0,5,10,15,20,25,30,35,40,45}, {0,6,12,18,24,30,36,42,48,54}, {0,7,14,21,28,35,42,49,56,63}, {0,8,16,24,32,40,48,56,64,72}, {0,9,18,27,36,45,54,63,72,81}};

int powers[P] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main()
{
    int a, b, c = 0, aDigit, bDigit, aDigitN, bDigitN, currentSum, carry;

    cin >> a >> b;

    for(aDigitN = 1; a; a /= 10, aDigitN++)
    {
        carry = 0;
        for(bDigitN = 1; b; b /= 10, bDigitN++)
        {
            aDigit = a % 10;
            bDigit = b % 10;

            currentSum = arr[aDigit][bDigit];
//            c += (currentSum % 10 + carry) * powers[aDigitN + bDigitN];
            carry = currentSum / 10;
        }
//        c += carry * powers[aDigitN * bDigitN];
    }

    cout << c;

    return 0;
}
