#include <stdio.h>
#include <string.h>
#include <conio2.h>

#include "pilha.h"

void Jogar(TpPilha &a, TpPilha &b, TpPilha &c)
{
	char pega, coloca;
	while(!Cheia(c.TOPO))
	{
		clrscr();
		printf("Pega: ");
		fflush(stdin); scanf("%c", &pega);
		
		printf("Coloca: ");
		fflush(stdin); scanf("%c", &coloca);
		
		if(pega == 'a' && coloca == 'b')
			Torre(a, b);
		else if(pega == 'a' && coloca == 'c')
			Torre(a, c);
		else if(pega == 'b' && coloca == 'a')
			Torre(b, a);
		else if(pega == 'b' && coloca == 'c')
			Torre(b, c);
		else if(pega == 'c' && coloca == 'b')
			Torre(c, b);
		else if(pega == 'c' && coloca == 'a')
			Torre(c, a);
		else
		{
			printf("\nErro");
			getch();
		}
			
		Exibir(a, b, c);
	}
	
	
}

int main(void)
{	
	TpPilha a, b, c;	
	
	Inicializa(a);
	Inicializa(b);
	Inicializa(c);
	
	for(int i = 3; i > 0; i--)
	{
		PUSH(a, i);
	}
		
	Jogar(a, b, c);
	
	clrscr();
	printf("Torre de Hahaha");
	return 0;
}
