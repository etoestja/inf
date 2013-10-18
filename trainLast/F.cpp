#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
		cout << arr[i];
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
		cpCharN(perm[permN++], arr);
//		printN(arr);
//		cout << endl;
//		try_this();
		return;
	}
	else
	{
		int* used1;
		char* arr1;
		for(int i = 0; i < N; i++)
		{
			if(!used[i])
			{
				arr1 = (char*) malloc(sizeof(char) * N);
				used1 = (int*) malloc(sizeof(int) * N);
				cpIntN(used1, used);
				cpCharN(arr1, arr);
				arr1[depth] = i;//uniq[i];
				used1[i] = 1;
				fill(depth + 1, used1, arr1);
				free(arr1);
				free(used1);
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
	for(int i = 0; i < permN; i += fact[N - uniqN])
	{
		for(int j = 0; j < len; j++)
		{
			num[j] = (perm[i][uniq0[str[j]]] + '0');
		}
		if(num[0] == '0') continue;
		num[len] = 0;
		number = atoll(num);
		if(gcdq == -1) gcdq = number;
		else gcdq = gcd(gcdq, number);
//		printNA(num, len);
//		cout << " " << number;
//		cout << endl;
	}

	for(long long i = 1; i * i <= gcdq; i++)
	{
		if(gcdq % i == 0)
			cout << i << " ";
	}
	if(gcdq != 1)
		cout << gcdq;
}

void printFact()
{
	for(int i = 0; i <= N; i++)
		cout << i << ": " << fact[i] << endl;
}

void printPerm(int w)
{
	for(int i = 0; i < permN; i += fact[N - w])
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
//	printPerm(2);

//	test();	
//	input();

	return(0);
}

