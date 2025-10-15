#include <stdio.h>
#include <string.h>

int Inverter(int vet[], int tam)
{
	if(tam == 0)
		return 1;
	else
	{
		printf("\n%d", vet[tam-1]);
		return Inverter(vet, tam-1);
	}
		
}

int main(void)
{
	int vet[7] = {456, 123, 543, 997, 890, 547, 854}, tam = 7;
	
	printf("Vetor antigo:");
	for(int i = 0; i < tam; i++)
		printf("\n%d", vet[i]);
	
	
	printf("\nVetor inverso:");
	Inverter(vet, tam);

}
