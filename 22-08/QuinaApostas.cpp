#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>

struct TpAposta
{
	int NrAposta, Apostados[7];
	char Data[11];	
};

void ExibirApostas(char NomeTxt[50])
{
	TpAposta Reg;
	FILE *PtrTxt = fopen(NomeTxt,"r");
	
	if(PtrTxt == NULL)
	{
		printf("\nErro de Abertura!\n");
	}
	else
	{
		fscanf(PtrTxt,"%d %s %d %d %d %d %d %d %d", &Reg.NrAposta, &Reg.Data, &Reg.Apostados[0], 
													&Reg.Apostados[1], &Reg.Apostados[2], 
													&Reg.Apostados[3], &Reg.Apostados[4], 
													&Reg.Apostados[5], &Reg.Apostados[6]);
		while(!feof(PtrTxt))
		{
			printf("\nNr. Aposta: %d\t Data: %s", Reg.NrAposta, Reg.Data);
			printf(" Numeros Apostados: ");
			for(int i = 0; i < 7; i++){
				printf("[%d] ", Reg.Apostados[i]);
			}
			fscanf(PtrTxt,"%d %s %d %d %d %d %d %d %d", &Reg.NrAposta, &Reg.Data, &Reg.Apostados[0], 
													&Reg.Apostados[1], &Reg.Apostados[2], 
													&Reg.Apostados[3], &Reg.Apostados[4], 
													&Reg.Apostados[5], &Reg.Apostados[6]);
		}
		fclose(PtrTxt);
	}
	getch();
} 

void GerarArquivoApostasPremiadas(char NomeTxt[50], int DezSorteados[5])
{
	TpAposta Reg;
	FILE *PtrTxt = fopen(NomeTxt,"r");
	FILE *PtrSort = fopen("DezSorteadas.txt","w");
	
	
	fscanf(PtrTxt,"%d %s %d %d %d %d %d %d %d", &Reg.NrAposta, &Reg.Data, &Reg.Apostados[0], 
													&Reg.Apostados[1], &Reg.Apostados[2], 
													&Reg.Apostados[3], &Reg.Apostados[4], 
													&Reg.Apostados[5], &Reg.Apostados[6]);
		while(!feof(PtrTxt))
		{
			int cont = 0;
			for(int i = 0; i < 7; i++){
				for(int j = 0; j < 5; j++){
					if(Reg.Apostados[i] == DezSorteados[j])
						cont++;
				}
			}
			
			if(cont == 3)
				fprintf(PtrSort,"Aposta %d: terno\n", Reg.NrAposta);
			else if(cont == 4)
				fprintf(PtrSort,"Aposta %d: quadra\n", Reg.NrAposta);
			else if(cont == 5)
				fprintf(PtrSort,"Aposta %d: quina\n", Reg.NrAposta);
			else 
				fprintf(PtrSort,"Aposta %d: nada\n", Reg.NrAposta);
			
			printf("\nAcertos %d: %d", Reg.NrAposta, cont);
			//fprintf(PtrSort,"Acertos %d: %d\n", Reg.NrAposta, Reg.acertos);
			fscanf(PtrTxt,"%d %s %d %d %d %d %d %d %d", &Reg.NrAposta, &Reg.Data, &Reg.Apostados[0], 
													&Reg.Apostados[1], &Reg.Apostados[2], 
													&Reg.Apostados[3], &Reg.Apostados[4], 
													&Reg.Apostados[5], &Reg.Apostados[6]);
		}
		
		
		fclose(PtrTxt);
		fclose(PtrSort);
	
}


int main(void){
	int NrSorteados [5] = {5, 15, 2, 10, 32};
	ExibirApostas("Aposta.txt");
	GerarArquivoApostasPremiadas("Aposta.txt", NrSorteados);
	return 0;
}

