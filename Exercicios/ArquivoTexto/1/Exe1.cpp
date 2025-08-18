 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 void Texto(void){
 	
 	FILE *Ptr = fopen("Texto.txt","w");
 	char text[100];
 	
 	printf("Digite: ");
 	fflush(stdin);
 	gets(text);
 	fputs(text, Ptr);
 	
 	FILE *PtrUpper = fopen("TextoUpper.txt","w");
 	
 	fprintf(PtrUpper,"Maiusculo: ");
 	strupr(text);
	fputs(text, PtrUpper);
 	fclose(Ptr);
 }
 
 int main(void){
 	
 	Texto();

 	return 0;
 }
