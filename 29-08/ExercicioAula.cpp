#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "Aula.h"


void NumAleatorios(void)
{
	
	FILE *Ptr = fopen("Numeros.txt","w");
	int cont = 0, num;
	
	
	do
	{
		num = rand()%2000+1;
		//printf("%d\n", num);
		fprintf(Ptr, "%d\n", num);
		cont++;
	}while(cont <= 2000);
	
	
	fclose(Ptr);

}

void B(TpPilha p)
{
	
	FILE *Ptr = fopen ("Numeros.txt","r");
	int op, num, contC = 0, soma = 0;
	
	
	srand(time(NULL));
	do
	{
		op = rand()%2;
		
		fscanf(Ptr, "%d", &num);
		//printf("\n%d", num);
		if(op == 1)
		{
			if(!Cheia(p.TOPO)){
				printf("\nInsere");
				PUSH(p, num);
			}
			else
				contC++;
				
		}
		else
		{
			if(!Vazia(p.TOPO)){
				printf("\nRetira");
				POP(p);
				soma += num;
			}
			
		}
		Sleep(100);
	}while(!kbhit());
	
	printf("\nQuantidade de vezes que a Pilha esteve Cheia: %d", contC);
	printf("\nSoma de todos os elementos retirados: %d", soma);
	printf("\n\nPilha atualizada: ");
	Exibe(p);
	
	fclose(Ptr);
	
}

int main(void){
	
	TpPilha p;
	
	Inicializa(p);
	NumAleatorios();
	B(p);

	return 0;
}


