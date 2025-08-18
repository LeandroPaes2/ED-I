 #include <stdio.h>
 #include <string.h>
 
 void Comparar(void){
 	
 	FILE *Arq1 = fopen("Arquivo1.txt","r");
 	FILE *Arq2 = fopen("Arquivo2.txt","r");
 	char caracter1, caracter2;
 	int conf = 0;
 	
 	caracter1 = fgetc(Arq1);
 	caracter2 = fgetc(Arq2);
 	while(!feof(Arq1))
 	{
 		if(caracter1 != caracter2)
 			conf = 1;
 		
 		caracter1 = fgetc(Arq1);
 		caracter2 = fgetc(Arq2);
	}
 	
 	if(conf == 1)
 		printf("\nNao sao identicos");
 	else
 		printf("\nSao identicos");
 	fclose(Arq1);
 	fclose(Arq2);
 }
 
 void Texto(void){
 	
 	FILE *Arq1 = fopen("Arquivo1.txt","w+");
 	FILE *Arq2 = fopen("Arquivo2.txt","w+");
 	char texto1[50], texto2[50];
 	
 	printf("Digite arq1: ");
 	fflush(stdin);
 	gets(texto1);
 	
 	printf("Digite arq2: ");
 	fflush(stdin);
 	gets(texto2);
 	
 	fputs(texto1, Arq1);
 	fputs(texto2, Arq2);
 	
 	fclose(Arq1);
 	fclose(Arq2);
 }
 
 int main(void){
 	
 	Texto();
 	Comparar();
 	return 0;
 }
