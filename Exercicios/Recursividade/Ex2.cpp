#include <stdio.h>

int Elevado(int x, int y)
{
	if(y == 1)
		return x;
	else
		return x * Elevado(x, y-1);
}

int main(void)
{
	printf("\n%d", Elevado(2, 3));
}
