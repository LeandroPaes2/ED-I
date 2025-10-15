#include <stdio.h>

int MDC(int x, int y)
{
	if(y == 0)
		return x;
	else
		return MDC(y, x%y);
}


int main(void)
{
	printf("%d", MDC(12, 18));
}
