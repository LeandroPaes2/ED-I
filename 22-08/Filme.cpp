#include<stdio.h>
#include<string.h> 
#include<conio2.h>
 
struct filme{
    char nome[60], classif[6];
    int ano, duracao;
    float gasto,renda,espec;
};
 
void MaiorLucroEspec(void){
	filme reg;
	char nomeL[60], nomeE[60];
	float maiorL = 0, maiorE = 0;
	
	FILE *arq = fopen("filmes.txt","r");
	
	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	while(!feof(arq))
	{
		if(maiorL < reg.renda){
			maiorL = reg.renda;
			strcpy(nomeL,reg.nome);
		}
		
		if(maiorE < reg.espec){
			maiorE = reg.espec;
			strcpy(nomeE,reg.nome);
		}
			
		fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	}
	printf("Maior lucro: %s com %.2f", nomeL, maiorL);
	printf("\nMaior taxa de espectadores: %s com %.2f", nomeE, maiorE);
	fclose(arq);
}  
 
void DuracaoM(void){
	filme reg;
	FILE *arq = fopen("filmes.txt","r");
	int cont = 0, soma = 0;
	float media;
	
	fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	while(!feof(arq))
	{
		
		soma += reg.duracao;
		cont++;
		fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	}
	media = soma/cont;
	printf("\nDuracao media dos filmes: %.2f", media);
	fclose(arq);
}  
 
int main()
{
    /*filme reg;
    FILE *arq = fopen("filmes.txt","r");
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    while(!feof(arq))
    {
          printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
     
          fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }
    printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
     
    fclose(arq);*/
    MaiorLucroEspec(); 
    DuracaoM();
    getch();
}


