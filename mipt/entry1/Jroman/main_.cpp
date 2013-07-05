#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::map;
using std::string;

const unsigned int M = 256, T = 13;
unsigned int lcount[M], used_l[M];

//                            0      1       2       3       4       5       6       7       8       9       10      11      12
string names[T] =            {"M",   "CM",   "D",    "CD",   "C",    "XC",   "L",    "XL",   "X",    "IX",   "V",    "IV",   "I"};
unsigned int values[T] =     {1000,  900,    500,    400,    100,    90,     50,     40,     10,     9,      5,      4,      1};
unsigned int lengths[T] =    {1,     2,      1,      2,      1,      2,      1,      2,      1,      2,      1,      2,      1};
unsigned int maxuse[T] =     {3,     1,      1,      1,      3,      1,      1,      1,      3,      1,      1,      1,      3};
//unsigned int maxuse[T] =     {3,     1,      1,      1,      3,      1,      1,      1,      3,      1,      1,      1,      3};
unsigned int used[T], used_save[T];

unsigned long long int min(unsigned long long int a, unsigned long long int b)
{
    return(a > b ? b : a);
}

unsigned int next_letter(unsigned int c)
{
    unsigned int i;
    for(i = c + 1; i < T; i++)
        if(used[i]) return(i);
    return(0);
}

int main()
{
    unsigned int i, si;
    for(i = 'A'; i <= 'Z'; i++) lcount[i] = 0;

    char c;
    while((c = cin.get()) && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    {
        if(c >= 'a' && c <= 'z') lcount[c - 'a' + 'A']++;
        else lcount[c]++;
    }

    unsigned long long int length, value, maxlength = 0, maxvalue = 0;

    for(used[0] = 0; used[0] <= maxuse[0]; used[0]++) //M
    {
        for(used[1] = 0; used[1] <= maxuse[1]; used[1]++) //CM
        {
            for(used[2] = 0; used[2] <= maxuse[2]; used[2]++) //D
            {
                for(used[3] = 0; used[3] <= maxuse[3]; used[3]++) //CD
                {
                    for(used[4] = 0; used[4] <= maxuse[4]; used[4]++) //C
                    {
                        for(used[5] = 0; used[5] <= maxuse[5]; used[5]++) //XC
                        {
                            for(used[6] = 0; used[6] <= maxuse[6]; used[6]++) //L
                            {
                                for(used[7] = 0; used[7] <= maxuse[7]; used[7]++) //XL
                                {
                                    for(used[8] = 0; used[8] <= maxuse[8]; used[8]++) //X
                                    {
                                        for(used[9] = 0; used[9] <= maxuse[9]; used[9]++) //IX
                                        {
                                            for(used[10] = 0; used[10] <= maxuse[10]; used[10]++) //V
                                            {
                                                for(used[11] = 0; used[11] <= maxuse[11]; used[11]++) //IV
                                                {
                                                    for(used[12] = 0; used[12] <= maxuse[12]; used[12]++) //I
                                                    {
                                                        if((used[0] + used[1]) <= lcount['M'] &&
                                                           (used[1] + used[3] + used[4] + used[5]) <= lcount['C'] &&
                                                           (used[2] + used[3]) <= min(1, lcount['D']) &&
                                                           (used[5] + used[7] + used[8] + used[9]) <= lcount['X'] &&
                                                           (used[6] + used[7]) <= min(1, lcount['L']) &&
                                                           (used[10] + used[11]) <= min(1, lcount['V']) &&
                                                           (used[9] + used[11] + used[12]) <= lcount['I'])
                                                        {
                                                            if(used[7])
                                                            {
                                                                si = next_letter(7);
                                                                if(si != 0 && si != 5 && si != 1 && si != 9 && si != 11) continue;
                                                            }
                                                            if(used[5])
                                                            {
                                                                si = next_letter(5);
                                                                if(si != 0 && si != 5 && si != 1 && si != 9 && si != 11) continue;
                                                            }
                                                            if(used[3])
                                                            {
                                                                si = next_letter(3);
                                                                if(si != 0 && si != 6 && si != 8 && si != 10 && si != 12 && si != 5 && si != 7 && si != 9 && si != 11) continue;
                                                            }
                                                            if(used[1])
                                                            {
                                                                si = next_letter(1);
                                                                if(si != 0 && si != 6 && si != 8 && si != 10 && si != 12 && si != 5 && si != 7 && si != 9 && si != 11) continue;
                                                            }
                                                            if(used[9] && (used[10] || used[11] || used[12])) continue;
                                                            if(used[11] && used[12]) continue;

                                                            length = 0;
                                                            value = 0;

                                                            for(i = 0; i < T; i++)
                                                            {
                                                                length += used[i] * lengths[i];
                                                                value += used[i] * values[i];
                                                            }

                                                            if(length >= maxlength)
                                                            {
                                                                maxlength = length;
                                                                maxvalue = value;

                                                                for(i = 0; i < T; i++) used_save[i] = used[i];
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(i = 0; i < T; i++)
    {
        for(si = 0; si < used_save[i]; si++)
            cout << names[i];
    }

    cout << endl;

    return 0;
}
