#include <iostream>
#include <cstdio>

using namespace std;

enum direction_ {D_UP, D_DOWN};

int direction = 0;
int oldDirection = 0;
int consDays = 0;
int money = 0;
int shares = 0;

int a = 0, b = 0;
int n = 0, d = 0;

int priceCurrent = 0, priceOld = 0;

inline void updatePrice()
{
    priceOld = priceCurrent;
    scanf("%d", &priceCurrent);
}

inline void buy()
{
    int N = min(money / priceCurrent, a * consDays);

    shares += N;
    money -= N * priceCurrent;
}

inline void sell()
{
    int N = min(shares, b * consDays);

    shares -= N;
    money += N * priceCurrent;
}

inline void action()
{
    if(priceCurrent > priceOld)
    {
        if(direction == D_UP)
        {
            consDays++;
        }
        else
            consDays = 1;

        direction = D_UP;

        buy();
    }
    else if(priceCurrent < priceOld)
    {
        if(direction == D_DOWN)
        {
            consDays++;
        }
        else
            consDays = 1;

        direction = D_DOWN;

        sell();
    }
}

int main()
{
    cin >> n >> d >> a >> b;

    money = d;
    direction = 0;
    consDays = 0;
    shares = 0;

    updatePrice();

    for(int i = 1; i < n; i++)
    {
        updatePrice();

        action();
    }

    cout << money << " " << shares << endl;

    return 0;
}

