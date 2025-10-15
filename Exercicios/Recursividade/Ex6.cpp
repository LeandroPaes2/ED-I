#include <stdio.h>
#include <string.h>

char PalavrasOrdemReversa(char Frase[])
{
	printf("%s", Frase);
	strtok(, " ");
	printf("%s", Frase);
	return 1;
}


int main(void)
{
	char frase[100];
	
	gets(frase);
	strtok(frase, " ");
	PalavrasOrdemReversa(frase);
	return 0;
}
