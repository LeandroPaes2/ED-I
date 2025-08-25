#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void EX4(void)
{
	FILE *Ptr = fopen("1arquivo.txt","r");
	FILE *EX4 = fopen("2arquivo.txt","w+");
	int pri = 1;
	char caracter;
	caracter = fgetc(Ptr);
	while(!feof(Ptr))
	{
		if(pri == 1)
			fputc(toupper(caracter),EX4);
		else
			fputc(caracter,EX4);
		pri = 0;
		caracter = fgetc(Ptr);
	}
	
	fclose(EX4);
}

void Texto(void)
{
	FILE *Ptr = fopen("1arquivo.txt","w+");
	char texto[100];
	printf("Digite: ");
	fflush(stdin); 
	gets(texto);
	
	fputs(texto,Ptr);
	
	
	
	
	
	fclose(Ptr);
	
}


int main(void){
	
	Texto();
	EX4();
	return 0;
}
