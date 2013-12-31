//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define NMAX 100

int N;
bool printMaxFirst = 1;

int arr[NMAX][NMAX];

int main() {
    cin >> N;

    int minCounter = 1;
    int maxCounter = 4 * N * N;

    int i, j;
    for(i = 0; i < 2 * N; i++)
    {
        printMaxFirst = ((i % 2) == 0);
        //cerr << "row " << i << " pmf=" << printMaxFirst << endl;
        for(j = 0; j < N; j++)
        {
            if(printMaxFirst)
            {
                arr[i][2 * j] = maxCounter;
                arr[i][2 * j + 1] = minCounter;
                cout << maxCounter << " " << minCounter << " ";
            }
            else
            {
                arr[i][2 * j] = minCounter;
                arr[i][2 * j + 1] = maxCounter;
                cout << minCounter << " " << maxCounter << " ";
            }
            maxCounter--;
            minCounter++;
        }
        //cout << endl;
    }
    cout << endl;

//    int maxSum = 0;
//
//#define uMaxSum(a) {if(maxSum < a) maxSum = a;}
//
//    for(int i = 0; i < 2 * N; i++)
//        for(int j = 0; j < 2 * N; j++)
//        {
//            if(i > 0)
//                uMaxSum(arr[i - 1][j]);
//            if(j > 0)
//                uMaxSum(arr[i][j - 1]);
//        }
//    cout << maxSum << endl;
//}

	return 0;
}
