#include <stdio.h>
#include <math.h>

typedef double num_t;

double eps = 0.01;

struct vect
{
    num_t x, y, z;
};

void vect_scan(struct vect* t_vect)
{
    scanf("%lf%lf%lf", &(t_vect->x), &(t_vect->y), &(t_vect->z));
}

num_t vect_abs_mult(struct vect* vect1, struct vect* vect2)
{
    return(fabs(vect1->x * vect2->x + vect1->y * vect2->y + vect1->z * vect2->z));
}

num_t vect_abs(struct vect* vect)
{
    return(sqrt(vect_abs_mult(vect, vect)));
}

int is_zero_eps(double val)
{
    return(val - fabs(val * 2 * eps) <= 0 && val + fabs(val * 2 * eps) >= 0);
}

int main(void)
{
    struct vect vect1, vect2;

    int result = 0;

    vect_scan(&vect1);
    vect_scan(&vect2);

    num_t abs = vect_abs(&vect1) * vect_abs(&vect2);

    if(abs != 0)
    {
        num_t rect = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
        if(is_zero_eps(rect))
            result = 1;

        int is_parr = 1;
        num_t parr = vect1.x * vect2.y - vect1.y * vect2.x;
        if(!is_zero_eps(parr))
            is_parr = 0;

        parr = vect1.x * vect2.z - vect1.z * vect2.x;
        if(!is_zero_eps(parr))
            is_parr = 0;

        parr = vect1.y * vect2.z - vect1.z * vect2.y;
        if(!is_zero_eps(parr))
            is_parr = 0;

        if(is_parr) result = 2;
    }
    /*else
    {
        //if(vect_abs(&vect1) != 0 || vect_abs(&vect2) != 0)
            //result = 2;
    }*/

    printf("%d\n", result);

    return 0;
}

