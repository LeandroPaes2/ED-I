#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>

#include "Funcoes.h"

char Menu(void)
{
	clrscr();
	printf("### M E N U # # #\n");
	printf("\n[A] Cadastrar");
	printf("\n[B] Exibir");
	printf("\n[ESC] Sair\n");
	
	return toupper(getche());
}

void Executar(void)
{
	char opcao;
	
	do{
		opcao = Menu();
		switch(opcao){
			
			case 'A': Cadastrar();
					break;
					
			case 'B': Exibir();
					break;
			
		}
		
	}while(opcao != 27); //ESC
}

int main(void){
	Executar();
	return 0;
}
