#include <stdio.h>
#include <conio2.h>
#include <string.h>
#include <stdlib.h>

#include "pilha.h"


void Executar(TpPilha &p)
{
	FILE * Ptr = fopen("Resultados.txt","r");
	char linha[50], caracter;
	int num1, num2, res;
	
	
	fgets(linha, 50, Ptr);
	while(!feof(Ptr))
	{
		for(int i = 0; i < strlen(linha); i++)
		{
			caracter = linha[i];
			
			if((caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/'))
			{
			 	num1 = POP(p);
			 	num2 = POP(p);
			 	
			 	if(caracter == '+')
			 		res = num1 + num2;
		 		if(caracter == '-')
		 			res = num1 - num2;
		 		if(caracter == '*')
		 			res = num1 * num2;
		 		if(caracter == '/')
		 			res = num1 / num2;
		 		
		 		PUSH(p, res);
			}
			else if(caracter >= '0' && caracter <= '9')
			{
				PUSH(p, caracter - '0');
			}
		}
		printf("Resultado = %d\n", POP(p));
		fgets(linha, 50, Ptr);	
	}	
	
	fclose(Ptr);
	

}


int main(void)
{
	TpPilha p;
	
	Inicializa(p);
	
	Executar(p);
	return 0;
}
