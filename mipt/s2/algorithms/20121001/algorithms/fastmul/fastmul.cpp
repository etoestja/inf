#include "fastmul.h"

//num_t fastmul(num_t a, num_t b)
//{
//    num_t c;
//    if(a == 0 || b == 0) return(0);
//    else if(a == 1) return(b);
//    else if(b == 1) return(a);
//    else
//    {
//        if(a % 2 == 0)
//        {
//            c = fastmul(a / 2, b);
//            return(c + c);
//        }
//        else if(b % 2 == 0)
//        {
//            c = fastmul(a, b / 2);
//            return(c + c);
//        }
//        else
//        {
//            c = fastmul((a - 1) / 2, b);
//            return(c + c + b);
//        }
//    }
//}

int fastmul(int a, int b)
{
    int c;
    if(a == 0 || b == 0) return(0);
    else
    {
        if(a % 2)
        {
            c = fastmul((a - 1) / 2, b);
            return(c + c + b);
        }
        else
        {
            c = fastmul(a / 2, b);
            return(c + c);
        }
    }
}
