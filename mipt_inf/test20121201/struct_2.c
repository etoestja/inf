//#define DEBUG 1
#undef DEBUG

#ifdef DEBUG
#include <stdio.h>
#include <stdlib.h>

struct Rect0
{
    int x;        // верхняя левая вершина, х-координата
    int y;        // верхняя левая вершина, y-координата
    int width;    // ширина
    int height;   // высота
};
struct Point
{
    int x;
    int y;
};
struct Rect1
{
    struct Point lt; // левая верхняя вершина
    struct Point rb; // правая нижняя вершина
};

int areaRect0(struct Rect0);
int areaRect1(struct Rect1);
#endif

int absolute(int x)
{
    return(x > 0 ? x : -x);
}

int areaRect0(struct Rect0 Rect)
{
    return(Rect.width * Rect.height);
}

int areaRect1(struct Rect1 Rect)
{
    return(absolute(Rect.lt.x - Rect.rb.x) * absolute(Rect.lt.y - Rect.rb.y));
}

#ifdef DEBUG

#define printPoint(t) printf("(%d %d)", (t).x, (t).y)

int main()
{
    struct Rect0 myRect0;
    myRect0.x = 123123;
    myRect0.y = 232;
    myRect0.width = 5;
    myRect0.height = 10;

    printf("myRect0(%d %d %d %d) and its area equals to %d\n", myRect0.x, myRect0.y, myRect0.width, myRect0.height, areaRect0(myRect0));

    struct Rect1 myRect1;
    myRect1.lt.x = -100;
    myRect1.lt.y = -10000;
    myRect1.rb.x = -99;
    myRect1.rb.y = -9999;

    printf("myRect1 ");
    printPoint(myRect1.lt);
    printf(" ");
    printPoint(myRect1.rb);
    printf(" and its area equals to %d\n", areaRect1(myRect1));

    return 0;
}
#endif
