#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define N 10
//#define N 4
#define L 512
#define WL 20
string str;
#define F10 (3628800 + 10)

int fact[N + 1];
char perm[F10][N];
int permN = 0;

void fillFact()
{
	int i = 0, f = 1;
	for(i = 0; i <= N; i++)
	{
		if(i > 0) f *= i;
		fact[i] = f;
	}
}

int test();

int M;

long long gcd(long long a, long long b)
{
	if (a*b == 0)
		return a+b;
	else
		return gcd(b, a % b);
}

int isBadPalyndrome(char* x, int len)
{
	vector<char> v1, v2;
	if(len % 2)
		return(0);
	for(int i = 0; i < len; i++)
	{
		if(i % 2 == 0)
			v1.push_back(x[i]);
		else
			v2.push_back(x[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	string y = x;
	for(int i = 0; i < len; i++)
	{
		if(i % 2 == 0)
		{
			y[i] = v1[i / 2];
		}
		else
			y[i] = v2[v2.size() - i / 2 - 1];
	}
       for(int i = 0; i < len / 2; i++)
               if(y[i] != y[len - i - 1])
                       return(0);

	return(1);
}

void input()
{
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		cout << "Case " << (i + 1) << ": ";
		test();
		cout << endl;
	}
}

int uniq0[L];
char uniq[N];
int uniqN;

void getUniq()
{
	uniqN = 0;
	for(int i = 0; i < L; i++)
		uniq0[i] = -1;

	for(int i = 0; i < str.length(); i++)
		uniq0[str[i]] = 1;
	for(int i = 0; i < L; i++)
		if(uniq0[i] == 1)
		{
			uniq0[i] = uniqN;
			uniq[uniqN] = i;
			uniqN++;
		}
}

void printN(char arr[N])
{
	cout << "[";
	for(int i = 0; i < N; i++)
		cout << ((char)(arr[i] + '0'));
	cout << "]";
}

void printNA(char* arr, int c)
{
	cout << "[";
	for(int i = 0; i < c; i++)
		cout << arr[i];
	cout << "]";
}

void cpCharN(char* dest, char src[N])
{
	for(int i = 0; i < N; i++)
		dest[i] = src[i];
}

void cpIntN(int* dest, int src[N])
{
	for(int i = 0; i < N; i++)
		dest[i] = src[i];
}

void fill(int depth, int used[N], char arr[N])
{
//	cout << "fill depth=" << depth << endl;
	if(depth == N)
	{
        return;
		cpCharN(perm[permN++], arr);
//		printN(arr);
//		cout << endl;
//		try_this();
		return;
	}
	else
	{
		for(int i = 0; i < N; i++)
		{
			if(!used[i])
			{
//				arr1 = (char*) malloc(sizeof(char) * N);
//				used1 = (int*) malloc(sizeof(int) * N);
//				cpIntN(used1, used);
//				cpCharN(arr1, arr);
				arr[depth] = i;//uniq[i];
                if(depth == N - 1)
                {
                    cpCharN(perm[permN++], arr);
                }
                else
                {
    				used[i] = 1;
    				fill(depth + 1, used, arr);
                    used[i] = 0;
                }
//				free(arr1);
//				free(used1);
			}
		}
	}
}

void printUniq()
{
	for(int i = 0; i < uniqN; i++)
	{
		cout << "uniq[" << i << "]=" << uniq[i] << endl;
	}
	for(unsigned char i = 0; i < 255; i++)
	{
		if(uniq0[i] != -1)
			cout << "uniq0[" << i << "]= " << uniq0[i] << endl;
	}
}

int test()
{
	cin >> str;
	int len = str.length();
	getUniq();
	char num[WL];
	//printUniq();
	long long gcdq = -1;
	/*for(int j = 0; j < len; j++)
	{
		cout << "str[" << j << "] = " << str[j] << endl;
	}*/
//return 0;

	long long number;
    int parts = 200;
    long quantity = fact[N] / fact[N - uniqN];
    int offsetMax = quantity / parts + 1;
    int posStep = offsetMax;
    int i, i11 = isBadPalyndrome((char*)str.c_str(), len);
    for(int offset = 0; offset < offsetMax; offset++)
        for(int pos = 0; (i = (pos + offset) * fact[N - uniqN]) < permN; pos += posStep)
        {
//            cout << "i=" << i << endl;
//	for(int i = 0; i < permN; i += 100/*fact[N - uniqN]*/)
       		for(int j = 0; j < len; j++)
       		{
       			num[j] = (perm[i][uniq0[str[j]]] + '0');
       		}
       		if(num[0] == '0') continue;
       		num[len] = 0;
       		number = atoll(num);
       		if(gcdq == -1) gcdq = number;
        	else gcdq = gcd(gcdq, number);
            if(gcdq == 1 || (i11 && gcdq == 11))
            {
                offset = offsetMax;
                break;
            }
//		printNA(num, len);
//		cout << " " << number;
//		cout << endl;
        }

    vector<long long> vect;
	for(long long i = 1; i * i <= gcdq; i++)
	{
		if(gcdq % i == 0)
        {
            if(i * i != gcdq)
                vect.push_back(i);
			cout << i << " ";
        }
	}

    vector<long long>::reverse_iterator rit;
    for(rit = vect.rbegin(); rit != vect.rend(); rit++)
        cout << gcdq / *rit << " ";
//	if(gcdq != 1)
//		cout << gcdq;
}

void printFact()
{
	for(int i = 0; i <= N; i++)
		cout << i << ": " << fact[i] << endl;
}

void printPerm(int w)
{
	for(int i = 0; i < permN; i += 1)
	{
		cout << i << ": ";
		printN(perm[i]);
		cout << endl;
	}
		
}

void fillPerm()
{
	char arr[N];
	int used[N];
	for(int i = 0; i < N; i++)
		used[i] = 0;

	fill(0, used, arr);
}

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	fillFact();
//	printFact();
	fillPerm();
//	printPerm(10);

//	test();	
	input();

	return(0);
}

