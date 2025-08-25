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
 
void ordenar(void)
{
	FILE *arq = fopen("filmes.txt", "r");

    filme filmes[200], aux;  
    int qtd = 0;

    while(fscanf(arq, "%[^;];%d;%[^;];%f;%f;%d;%f\n",
                 filmes[qtd].nome, &filmes[qtd].ano, filmes[qtd].classif,
                 &filmes[qtd].gasto, &filmes[qtd].renda,
                 &filmes[qtd].duracao, &filmes[qtd].espec) == 7)
    {
        qtd++;
    }
    fclose(arq);

    // (Bubble Sort)
    for(int i=0; i<qtd-1; i++){
        for(int j=i+1; j<qtd; j++){
            if(filmes[i].ano > filmes[j].ano){ 
                aux = filmes[i];
                filmes[i] = filmes[j];
                filmes[j] = aux;
            }
        }
    }

    arq = fopen("filmes.txt", "w");
    for(int i=0; i<qtd; i++){
        fprintf(arq, "%s;%d;%s;%.3f;%.3f;%d;%.1f\n",
                filmes[i].nome, filmes[i].ano, filmes[i].classif,
                filmes[i].gasto, filmes[i].renda,
                filmes[i].duracao, filmes[i].espec);
    }
    fclose(arq);

}
 
void AnosFilmes(void)
{
	filme reg;
    FILE *arq = fopen("filmes.txt","r");
    int aux = 0, contAno = 0, anoMais = 0, maximo = 0;
    
    ordenar();
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    while(!feof(arq))
    {

        if(reg.ano != aux)
        {
        	if(contAno > maximo){
                maximo = contAno;
                anoMais = aux;
            }
            aux = reg.ano;
            contAno = 1;
		}
		else
			contAno++;
			
		if(contAno > maximo)
		{
	        maximo = contAno;
	        anoMais = aux;
		}
     
        fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
     
    }

	printf("\nAno com mais filmes: %d qtde: %d filmes\n", anoMais, maximo);
     
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
    AnosFilmes();
    getch();
}


