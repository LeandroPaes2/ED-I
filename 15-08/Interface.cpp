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
	printf("\n[C] Exclusao (Fisica) pelo Codigo");
	printf("\n[D] Alterar");
	printf("\n[E] Mostrar o txt em char");
	printf("\n[F] Mostrar o txt em string");
	printf("\n[G] CapsLock char");
	printf("\n[h] CapsLock string");
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
			
			case 'C': ExclusaoFisica();
					break;

			case 'D': Alterar();
					break;	
					
			case 'E': MostrarTxtChr("Relatorio.txt");
					break;		
					
			case 'F': MostrarTxtStr("Relatorio.txt");
					break;
					
			case 'G': UpperTxtChr("Relatorio.txt");
					break;
			
			case 'H': UpperTxtStr("Relatorio.txt");
					break;
		}
		
	}while(opcao != 27); //ESC
}

int main(void){
	Executar();
	return 0;
}
