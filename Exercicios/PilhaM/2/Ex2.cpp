 #include <stdio.h>
 #include <string.h>
 #include <conio2.h>
 
 #include "pilhaM.h"

void ExcluirElem(PilhaM &p)
{
	int elem;
	
	printf("\nDigite um elemento para excluir: ");
	scanf("%d", &elem);
	
	Excluir(p, elem, 1);
}

void Executar(PilhaM &p)
{
 	int elem;
 	
 	do
 	{
 		printf("Digite: ");
 		scanf("%d", &elem);
 		if(elem != 0)
 			PUSH(p,elem, 1);
	}while(!Cheia(p.TOPO1, p.TOPO2) && elem != 0);
 	
 }
 
 int main(void)
 {
 	PilhaM p;
 	
 	inicializar(p);
 	
 	Executar(p);
 	printf("\nPilha Atual:\n");
 	Exibir(p, 1);
 	
 	
 	ExcluirElem(p);
 	printf("\nPilha Atualizada:\n");
 	Exibir(p, 1);
 	return 0;
 }
