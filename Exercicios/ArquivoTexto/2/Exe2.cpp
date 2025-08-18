 #include <stdio.h>
 #include <string.h>
 

 void Texto(void){
 	
 	FILE *Ptr = fopen("ArquivoQualquer.txt","w+");
 	char texto[100];
 	int qtde = 0, i;
 	printf("Digite: ");
 	gets(texto);
 	fputs(texto, Ptr);
 	
	for(i = 0; i < strlen(texto); i++)
	{

		if(texto[i] != ' '){
			qtde++;
		}
	}
	
 	printf("Quantidade de letras: %d", qtde);
 	fclose(Ptr);
 }
 
 int main(void){
 	
 	Texto();

 	return 0;
 }
