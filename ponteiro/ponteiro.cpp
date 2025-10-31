#include <stdio.h>

int main(void)
{
	int a;
	int *p;
	
	a = 10;
	p = &a;
	
	printf("*p: %d\n", *p);
	printf("p: %d\n", p);
	printf("a: %d", a);
}
