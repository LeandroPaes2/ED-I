#include <stdio.h>
#include <string.h>
#include <conio2.h>

#include "pilha.h"

void Inserir(TpPilha &p)
{
	int elem;
	printf("Digite a pilha:\n");
	
	do
	{
		scanf("%d", &elem);
		PUSH(p, elem);
	}while(!Cheia(p.TOPO));
}

int main(void)
{
	TpPilha p;
	
	Inicializa(p);
	
	Inserir(p);
	printf("\nPilha: ");
	Exibir(p);
	printf("\nPilha Inversa: ");
	Inversa(p);
	return 0;
}
