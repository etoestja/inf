#include <stdio.h>

int main()
{
        long long n, c = 0;
            scanf("%lld", &n);

                if(n == 3)
                        {
                                    printf("3");
                                            return;
                                                }

                                                    while(n)
                                                            {
                                                                        if(n % 2 == 0)
                                                                                    {
                                                                                                    n /= 2;
                                                                                                    //            printf("%lld/2\n", n);
                                                                                                            }
                                                                                                                    else
                                                                                                                                {
                                                                                                                                                if((n % 4) == 1)
                                                                                                                                                                {
                                                                                                                                                                    //                printf("%lld--\n", n);
                                                                                                                                                                                    n--;
                                                                                                                                                                                                }
                                                                                                                                                                                                            else
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                //                printf("%d++\n", n);
                                                                                                                                                                                                                                                n++;
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                            c++;
                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                    printf("%lld", c);
}
