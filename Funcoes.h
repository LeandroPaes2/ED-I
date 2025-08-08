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
	rewind(arq);
	
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
			printf("\nCodigo ja existe!!!");
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
	
	fclose(PtrArq);
	getch();
}


