#include <stdio.h>
#include <conio2.h>
#include <string.h>
#include <stdlib.h>

#include "pilha.h"


void Executar(TpPilha &p)
{
	FILE * Ptr = fopen("Resultados.txt","r");
	char caracter;
	int num1, num2, res, cont = 0;
	rewind(Ptr);
	caracter = fgetc(Ptr);
	
	while(!feof(Ptr))
	{
		if((caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/') && cont >= 2)
		{
		 	num1 = POP(p);
		 	num2 = POP(p);
		 	if(caracter == '+')
		 		res += num1 + num2;
	 		if(caracter == '-')
	 			res += num1 - num2;
	 		if(caracter == '*')
	 			res += num1 * num2;
	 		if(caracter == '/')
	 			res += num1 / num2;
		}
		else
		{
			caracter = caracter-48;
			cont++;
			PUSH(p, res);
		}
		caracter = fgetc(Ptr);	
	}	
	Exibir(p);
}


int main(void)
{
	TpPilha p;
	
	Inicializa(p);
	
	Executar(p);
	return 0;
}
