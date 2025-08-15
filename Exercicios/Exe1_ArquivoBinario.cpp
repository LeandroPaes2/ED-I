#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio2.h>
#include <locale.h>

#include "Tad_Exe1.h"

Menu(void){
	
	clrscr();
	printf("\n* * * MENU * * *\n\n");
	printf("[A] Cadastro Produto\n");
	printf("[B] Cadastro Fornecedor\n");
	printf("[C] Consulta Produto\n");
	printf("[ESC] Sair\n");
	printf("Opção: ");
	return toupper(getche());
}

Executar(void){
	char op;
	
	do
	{
		op = Menu();
		switch(op){
			case 'A': CadastroProd();
				break;
			case 'B': CadastroForn();
				break;
			case 'C': ConsultasProd();
				break;
		}
	}while(op != 27);
	
}


int main(void){
	setlocale(LC_ALL, "Portuguese_Brasil.1252");
	system("chcp 1252 > nul"); // Troca o code page do console para aceitar acentos
	Executar();
	return 0;
}
