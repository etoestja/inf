#include <stdio.h>

int main()
{
	int cont = 1;
	int i, n;
	char c;
	while(cont)
	{
		if(scanf("%d", &n) > 0)
		{
			scanf("%c", &c);
			if(c == '@') c = 'c';
			for(i = 0; i < n; i++)
				printf("%c", c);
		}
		else if(scanf("%c", &c) > 0)
		{
			if(c == '@') c = 'c';
			if(c >= 'a' && c <= 'z')
				printf("%c", c);
			else
				cont = 0;
		}
		else
			cont = 0;
	}

	printf("\n");
	return(0);
}
