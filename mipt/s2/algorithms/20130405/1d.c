#include <stdio.h>

// || 1 1 1 ||
// || 2 1 3 ||
// || 1 0 0 || = A
// || 0 1 0 ||
// || 0 0 1 ||

// || 1 2 1 0 0 ||
// || 1 1 0 1 0 ||  = A^T
// || 1 3 0 0 1 ||

// || 1000 1200 12000 || = c^T

// || 60 100 40 30 20 || = b^T

// yTA>=CT
// y >= 0
// min y^Tb

int y1, y2, y3, y4, y5;

inline int test()
{
    return
    (
        (y1 + 2 * y2 + y3 >= 1000) &&
        (y1 + y2 + y4 >= 1200) &&
        (y1 + 3 * y2 + y5 >= 12000)
    );
}

int main()
{
    int z1, z2, z3, z4, z5;
    for(y1 = 0; y1 <= y2
    return(0);
}
