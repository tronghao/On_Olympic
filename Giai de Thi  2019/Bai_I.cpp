#include "stdio.h"
#include "windows.h"

int main()
{
	long long int r=100000, g=100000, b=100000, n=100000000000000;
	//printf("Nhap R G B n: ");
	//scanf("%lld%lld%lld%lld", &r, &g, &b, &n);
	//printf("\n%lld", n);
	if(n%3 == 2)
	{
		printf("\nKq: %3lldd %3lldd %3lld", r+g, b, g);
	}		
	else if(n%3 == 0)
	{
		printf("\nKq: %3lld %3lld %3lld", b, g+b, r);
	}
	else
	{
		printf("\nKq: %3lld %3lld %3lld", g, r, b+r);
	}
	
	return 0;
}

