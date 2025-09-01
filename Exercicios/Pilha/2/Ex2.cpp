#include <stdio.h>
#include <conio2.h>
#include <string.h>

#include "pilha.h"

void Excluir(TpPilha &p)
{
	int elem;
	
	printf("Digite um numero da pilha para EXCLUIR: ");
	scanf("%d", &elem);
	
	ExcluirPos(p, elem);
	
}

void Inseir(TpPilha &p)
{
	int i = 0, elem;
	
	printf("Pilha: \n");
	
	while(!Cheia(p.TOPO))
	{
		printf("pos[%d]: ", i++);
		scanf("%d", &elem);
		PUSH(p, elem);
	}
}

int main(void)
{
	TpPilha p;
	
	Inicializa(p);
	
	Inseir(p);
	Excluir(p);
	Exibir(p);
	return 0;
}
