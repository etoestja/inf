#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

const unsigned int M = 256, T = 13;
unsigned long long int lcount[M], used_l[M];

//                            0      1       2       3       4       5
//    6       7       8       9       10      11      12
string names[T] =            {"M",   "CM",   "D",    "CD",   "C",    "XC",
    "L",    "XL",   "X",    "IX",   "V",    "IV",   "I"};
unsigned int values[T] =     {1000,  900,    500,    400,    100,    90,
    50,     40,     10,     9,      5,      4,      1};
unsigned int lengths[T] =    {1,     2,      1,      2,      1,      2,
    1,      2,      1,      2,      1,      2,      1};
unsigned int maxuse[T] =     {3,     1,      1,      1,      3,      1,
    1,      1,      3,      1,      1,      1,      3};
unsigned int used[T], used_save[T];

void get_roman(unsigned int N)
{
    unsigned int i = 0;
    for(i = 0; i < T;)
    {
        if(values[i] <= N)
        {
            N -= values[i];
            used[i]++;
        }
        else i++;
    }
}

int main()
{
    unsigned int i, si, ssi;
    for(i = 0; i <= 255; i++) lcount[i] = 10;

    unsigned long long int length, value, maxlength = 0, maxvalue = 0;

    for(i = 0; i < T; i++) used_save[i] = 0;

    for(i = 1; i <= 3999; i++)
    {
        for(si = 0; si < T; si++) used[si] = 0;
        get_roman(i);

        if(((used[0] + used[1]) <= lcount['M']) &&
            ((used[1] + used[3] + used[4] + used[5]) <= lcount['C']) &&
            ((used[2] + used[3]) <= lcount['D']) &&
            ((used[5] + used[7] + used[8] + used[9]) <= lcount['X']) &&
            ((used[6] + used[7]) <= lcount['L']) &&
            ((used[10] + used[11]) <= lcount['V']) &&
            ((used[9] + used[11] + used[12]) <= lcount['I'])
        )
        {
            cout << "./tester ";
            for(ssi = 0; ssi < T; ssi++)
                for(si = 0; si < used[ssi]; si++) cout << names[ssi];
            cout << endl;
        }
        //cout << endl;
    }

    return 0;
}
