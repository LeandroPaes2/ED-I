#include <stdio.h>
#include <string.h>
#include <conio2.h>

#include "pilha.h"

void Inserir(TpPilha p1,TpPilha p2)
{
	int elem;
	
	printf("\nPilha 1:\n");
	do
	{
		scanf("%d", &elem);
		if(elem != 0)
			PUSH(p1, elem);
	}while(!Cheia(p1.TOPO) && elem != 0);
	
	
	printf("\nPilha 2:\n");
	do
	{
		scanf("%d", &elem);
		if(elem != 0)
			PUSH(p2, elem);
	}while(!Cheia(p2.TOPO) && elem != 0);
	
	
	printf("\nPilha 1 com concatenacao: \n");
	Concatena(p1, p2);
	Exibir(p1);
	
}

int main(void)
{
	TpPilha p1, p2;
	
	Inicializa(p1);
	Inicializa(p2);
	
	Inserir(p1, p2);
	
	return 0;
}
