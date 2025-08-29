#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>

#include "Pilha.h"

char Menu(void)
{
	clrscr();
	printf("MENU\n");
	printf("\n[A] Inserir Pilha");
	printf("\n[B] Retirar Pilha");
	printf("\n[C] Elemento Topo");
	printf("\n[D] Exibir");
	printf("\nOpcao: ");
	return toupper(getche());
	
}


int main(void){
	
	TpPilha p;
	char op;
	int elem;
	Inicializa(p);
	
	do{
		op = Menu();
		switch(op){
			case 'A': 
					if(!Cheia(p.TOPO)){
						printf("\nDigite o elemento: ");
						scanf("%d", &elem);
						PUSH(p, elem);
					}
					else
					{
						printf("\nPilha Cheia");
						getch();
					}
				
				break;
				
			case 'B':
					if(!Vazia(p.TOPO)){
						POP(p);
						printf("\nElemento Retirado!!");
						getch();
					}
					else{
						printf("\nPilha Vazia");
						getch();
					}
						
						
				break;
				
			case 'C':
					printf("\nElemento topo: %d", ElementoTopo(p));
					getch();
				break;
				
			case 'D':
					Exibe(p);
				break;
				
		}
	}while(27 != op);
		
	
	return 0;
}
