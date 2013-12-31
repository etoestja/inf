#include <stdio.h>

/*int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}*/

int binpow (int a, int n) {
	int res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			--n;
		}
		else {
			a *= a;
			n >>= 1;
		}
	return res;
}


int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d", binpow(a, b));
    return(0);
}
