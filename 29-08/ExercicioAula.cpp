#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Aula.h"


void NumAleatorios(TpPilha p)
{
	
	FILE *Ptr = fopen("Numeros.txt","w");
	int cont = 0, num, soma = 0;
	srand(time(NULL));
	do
	{
		num = rand()%2000+1;
		printf("%d\n", num);
		fprintf(Ptr, "%d\n", num);
		PUSH(p, num);
		soma += num;
		cont++;
	}while(cont <= 2000);
	
	printf("\nFinal de Arquivo");
	
	fclose(Ptr);

}

void B(TpPilha p, int soma)
{
	
	FILE *Ptr = fopen ("Numeros.txt","r");
	
	printf("\nRetirando: ");
	do
	{
		printf("\n%d", POP(p));
		Sleep(500);
		
	}while(!kbhit());
	
	fclose(Ptr);
}

int main(void){
	
	TpPilha p;
	int soma;
	Inicializa(p);
	NumAleatorios(p);
	B(p, soma);
	printf("\n\nPilha atualizada!!!");
	Exibe(p);
	return 0;
}


