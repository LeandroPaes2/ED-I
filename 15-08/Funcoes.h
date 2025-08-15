//Estruturas de Dados

struct TpDado{
	int Codigo;
	char Nome[20];
	float Salario;	
};

//Funçôes que manipulam esse dados

int Busca(int cod, FILE *arq)
{
	TpDado Reg;
	rewind(arq); //fseek(Ptr,0,0)
	
	fread(&Reg, sizeof(TpDado),1,arq);
	while(!feof(arq) && cod != Reg.Codigo)
		fread(&Reg, sizeof(TpDado),1,arq);
		
	if(!feof(arq))
		return ftell(arq) - sizeof(TpDado);
	else
		return -1;
}


void Cadastrar(void)
{
	TpDado Reg;
	FILE *PtrArq = fopen("Dados.dat", "ab+");
	int pos;
	
	printf("\n\n# # # C A D A S T R A R # # #\n");
	
	
	printf("\nCodigo: ");
	scanf("%d", &Reg.Codigo);
	
	
	while(Reg.Codigo > 0){
		
		pos = Busca(Reg.Codigo, PtrArq);
		if(pos != -1)
		{
			fseek(PtrArq, pos,0);
			fread(&Reg, sizeof(TpDado),1,PtrArq);
			printf("\nCodigo ja existe!\nNome: %s\n", Reg.Nome);
		}
		else
		{
			printf("\nNome: ");
		    fflush(stdin);
		    gets(Reg.Nome);
		    
		    printf("Salario: R$ ");
		    scanf("%f", &Reg.Salario);
			
			fwrite(&Reg, sizeof(TpDado),1,PtrArq);
		
		}
		printf("\nCodigo: ");
		scanf("%d", &Reg.Codigo);
		
	}
	
	
	fclose(PtrArq);
	getch();
}
void RelatorioArquivo(void);
void Exibir(void)
{
	TpDado Reg;
	FILE *PtrArq = fopen("Dados.dat", "r");
	printf("\n\n# # # E X I B I R # # #\n");
	
	if(PtrArq == NULL){
		printf("\nErr");
	}
	else
	{
		fread(&Reg, sizeof(TpDado),1,PtrArq);
		while(!feof(PtrArq)){
			
			printf("\nCodigo: %d", Reg.Codigo);
			printf("\nNome: %s", Reg.Nome);
			printf("\nSalario: R$ %.2f\n", Reg.Salario);
			
			fread(&Reg, sizeof(TpDado),1,PtrArq);
		}
	}
	RelatorioArquivo();
	fclose(PtrArq);
	getch();
}

void ExclusaoFisica(void)
{
	TpDado Reg;
	FILE *PtrArq = fopen("Dados.dat","rb");
	int pos, aux;
	
	printf("\n# # # Excluir pelo Codigo # # #\n");
	if(PtrArq == NULL){
		printf("\nErro de Abertura!\n");
	}
	else
	{
		printf("\nCodigo a Excluir: ");
		scanf("%d", &aux);
		pos = Busca(aux, PtrArq);
		
		if(pos == -1){
			printf("\nCodigo nao Encontrado!\n");
			fclose(PtrArq);
		}
		else
		{
			
			printf("\n# # # Detalhes do Dado Encontrado # # #\n");
			fseek(PtrArq, pos, 0);
			fread(&Reg, sizeof(TpDado), 1, PtrArq);
			
			printf("\nCodigo: %d", Reg.Codigo);
			printf("\nNome: %s", Reg.Nome);
			printf("\nSalario: R$ %.2f", Reg.Salario);
			
			printf("\nConfirmar Exclusao (S/N)? ");
			if(toupper(getche()) == 'S')
			{
				fseek(PtrArq, 0, 0);
				FILE *Novo = fopen("Novo.dat","wb");
				fread(&Reg, sizeof(TpDado), 1, PtrArq);
				while(!feof(PtrArq))
				{
					if(aux != Reg.Codigo)
					{
						fwrite(&Reg, sizeof(TpDado), 1, Novo);
					}
					fread(&Reg, sizeof(TpDado), 1,PtrArq);
				}	
				fclose(PtrArq);
				fclose(Novo);
				remove("Dados.dat");
				rename("Novo.dat","Dados.dat");
				printf("\nRegistro Excluido!\n");	
			}
			else
				fclose(PtrArq);
		}	
	}
	
	getch();
}


void Alterar(void){
	
	TpDado Reg;
	FILE *Ptr = fopen("Dados.dat","rb+");
	int pos;
	
	printf("\n# # # Alterar # # #\n");
	
	if(Ptr == NULL)
	{
		printf("\nErro de abertura!");
	}
	else
	{
		printf("\nDigite o codigo: ");
		scanf("%d", &Reg.Codigo);
		pos = Busca(Reg.Codigo, Ptr);
		
		if(pos == -1)
		{
			printf("\nCodigo nao encontrado!");
		}
		else
		{
			printf("\n# # # Alterar # # #\n");
			fseek(Ptr, pos, 0);
			fread(&Reg, sizeof(TpDado), 1, Ptr);
			
			printf("\nDados Atual:");
			printf("\nCodigo: %d", Reg.Codigo);
			printf("\nNome: %s", Reg.Nome);
			printf("\nSalario: R$ %.2f", Reg.Salario);
			
			printf("\n\nDados Novos:");
			printf("\nNome: "); fflush(stdin);
			gets(Reg.Nome);
			
			printf("\nSalario: ");
			scanf("%f", &Reg.Salario);
			
			printf("\nAlterado com sucesso!");
			fseek(Ptr, pos, 0);
			fwrite(&Reg, sizeof(TpDado), 1, Ptr);
		}
	}
	fclose(Ptr);
	getch();
	
}

void RelatorioArquivo(void)
{
	TpDado Reg;
	FILE *PtrArq = fopen("Dados.dat", "r");
	if(PtrArq == NULL){
		printf("\nErr");
	}
	else
	{
		FILE *PtrTxt = fopen("Relatorio.txt","wb");
		fprintf(PtrTxt,"\n=======================");
		fprintf(PtrTxt,"\n# # # E X I B I R # # #");
		fprintf(PtrTxt,"\n=======================\n");
		fread(&Reg, sizeof(TpDado),1,PtrArq);
		while(!feof(PtrArq)){
			
			fprintf(PtrTxt,"\nCodigo: %d", Reg.Codigo);
			fprintf(PtrTxt,"\nNome: %s", Reg.Nome);
			fprintf(PtrTxt,"\nSalario: R$ %.2f\n", Reg.Salario);
			
			fread(&Reg, sizeof(TpDado),1,PtrArq);
		}
		fclose(PtrTxt);
	}

	fclose(PtrArq);
	getch();
}

void MostrarTxtChr(char NomeArq[50])
{
	
	FILE *PtrTxt = fopen(NomeArq,"r");
	char caracter;
	clrscr();
	if(PtrTxt == NULL){
		printf("\nErro de Abertura!\n");
	}
	else
	{
		caracter = fgetc(PtrTxt);
		while(!feof(PtrTxt))
		{
			printf("%c", caracter);
			caracter = fgetc(PtrTxt);
		}
		fclose(PtrTxt);
	}
	printf("\n* * * Fim do Arquivo * * *\n");
	getch();
	
}

void MostrarTxtStr(char NomeArq[50])
{
	FILE *PtrTxt = fopen(NomeArq,"r");
	char linha[100];
	clrscr();
	if(PtrTxt == NULL){
		printf("\nErro de Abertura!\n");
	}
	else
	{
		fgets(linha,100,PtrTxt);
		while(!feof(PtrTxt))
		{
			printf("%s", linha);
			fgets(linha,100,PtrTxt);
		}
		fclose(PtrTxt);
	}
	printf("\n* * * Fim do Arquivo * * *\n");
	getch();
}

void UpperTxtChr(char NomeArq[50])
{
	
	FILE *PtrTxt = fopen(NomeArq,"r");
	char caracter;
	clrscr();
	if(PtrTxt == NULL){
		printf("\nErro de Abertura!\n");
	}
	else
	{
		FILE *PtrUpper = fopen("Upper.txt","w");
		caracter = fgetc(PtrTxt);
		while(!feof(PtrTxt))
		{
			fputc(toupper(caracter), PtrUpper);
			caracter = fgetc(PtrTxt);
		}
		fclose(PtrTxt);
		fclose(PtrUpper);
	}
	printf("\n* * * Fim do Arquivo * * *\n");
	getch();
	
}

void UpperTxtStr(char NomeArq[50])
{
	
	FILE *PtrTxt = fopen(NomeArq,"r");
	char linha[100];
	clrscr();
	if(PtrTxt == NULL){
		printf("\nErro de Abertura!\n");
	}
	else
	{
		FILE *PtrUpper = fopen("UpperSTR.txt","w");
		fgets(linha,100,PtrTxt);
		while(!feof(PtrTxt))
		{
			strupr(linha);
			fputs(linha,PtrUpper);
			fgets(linha,100,PtrTxt);
		}
		fclose(PtrTxt);
		fclose(PtrUpper);
	}
	printf("\n* * * Fim do Arquivo * * *\n");
	getch();
	
}










