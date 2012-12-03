//#include <stdio.h>

//struct Complex {
//    float a;
//    float b;
//};

struct Complex prod(struct Complex c1, struct Complex c2)
{
    struct Complex res;
    res.a = c1.a * c2.a - c1.b * c2.b;
    res.b = c1.a * c2.b + c1.b * c2.a;
    return(res);
}


//int main(void)
//{

//    return 0;
//}

