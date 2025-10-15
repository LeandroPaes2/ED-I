#include <stdio.h>

int mdc(int x, int y)
{
	if(x == y)
		return y;
	else if(x < y)
		return mdc(y, x);
	else if(x > y)
		return mdc(x-y, y);
}


int main(void)
{
	printf("%d", mdc(60, 40));
	
	return 0;
}
