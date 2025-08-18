 
 struct TpProduto{
	int cod, codForn;
	float preco;
	char nome[30];
	
 };
 
 struct TpFornecedor{
	int cod;
	char nome[30];
 };
 
 //Buscas
 
 int BuscaProd(int prod, FILE *Ptr){

	TpProduto Reg;
	rewind(Ptr);
	
	fread(&Reg,sizeof(TpProduto),1,Ptr);
	while(!feof(Ptr) && prod != Reg.cod)
		fread(&Reg,sizeof(TpProduto),1,Ptr);
		
	if(!feof(Ptr))
		return ftell(Ptr) - sizeof(TpProduto);
	else
		return -1;
		
 }
 
 int BuscaProdForn(int forn, FILE *Ptr){

	TpProduto Reg;
	rewind(Ptr);
	
	fread(&Reg,sizeof(TpProduto),1,Ptr);
	while(!feof(Ptr) && forn != Reg.codForn)
		fread(&Reg,sizeof(TpProduto),1,Ptr);
		
	if(!feof(Ptr))
		return ftell(Ptr) - sizeof(TpProduto);
	else
		return -1;
		
 }
 
 int BuscaForn(int forn, FILE *Ptr){

	TpFornecedor Reg;
	rewind(Ptr);
	
	fread(&Reg,sizeof(TpFornecedor),1,Ptr);
	while(!feof(Ptr) && forn != Reg.cod)
		fread(&Reg,sizeof(TpFornecedor),1,Ptr);
		
	if(!feof(Ptr))
		return ftell(Ptr) - sizeof(TpFornecedor);
	else
		return -1;
		
 }
 
 //Cadastros
 
 void CadastroProd(void){
 	
	TpProduto Reg;
	FILE *PtrProd = fopen("Produto.dat","ab+");
	FILE *PtrForn = fopen("Fornecedor.dat","r");
	int pos1, pos2;
	
	clrscr();
	printf("\n* * * Cadastro de Produto * * *\n\n");
 	
 	if(PtrForn == NULL){
 		printf("\nNão tem nenhum fornecedor castrado!!!");
	}
	else{
		printf("\nDigite o codigo: ");
		scanf("%d", &Reg.cod);
		while(Reg.cod > 0){
			
			pos1 = BuscaProd(Reg.cod, PtrProd);
			if(pos1 != -1)
			{
				printf("\nCodigo do Produto já cadastrado!!!");
			}
			else
			{
				printf("\nDigite o codigo do Fornecedor: ");
				scanf("%d", &Reg.codForn);
				pos2 = BuscaForn(Reg.codForn, PtrForn);
				if(pos2 == -1)
				{
					printf("\nCodigo do Fornecedor não encontrado!!!");
				}
				else
				{
					printf("Digite o nome do Produto: "); fflush(stdin);
					gets(Reg.nome);
					
					printf("Digite o preço: R$ ");
					scanf("%f", &Reg.preco);
					
					fwrite(&Reg, sizeof(TpProduto),1,PtrProd);
				}
			}
			
			printf("\nDigite o codigo: ");
			scanf("%d", &Reg.cod);
		}
	}
	
	
	
	fclose(PtrProd);
	fclose(PtrForn);
	getch();
 }
 
 void CadastroForn(void){
 	
 	TpFornecedor Reg;
 	FILE *Ptr = fopen("Fornecedor.dat","ab+");
 	int pos;
 	
 	clrscr();
 	printf("\n* * * Cadastro de Fornecedor * * *\n\n");
 	
 	printf("\nDigite o codigo: ");
 	scanf("%d", &Reg.cod);
 	while(Reg.cod > 0)
	{
 		pos = BuscaForn(Reg.cod, Ptr);
 		if(pos != -1)
 		{
 			printf("\nCodigo do Fornecedor já cadastrado!!!");
		}
		else
		{
			printf("\nDigite o nome: "); fflush(stdin);
 			gets(Reg.nome);
 			
 			fwrite(&Reg, sizeof(TpFornecedor), 1, Ptr);
		}
 		
		printf("\nDigite o codigo: ");
 		scanf("%d", &Reg.cod);
	}
	
	fclose(Ptr);
	getch();
 }
 
 //Consulta
 
 void ConsultasProd(void){
 	
 	TpProduto Reg;
 	FILE *Ptr = fopen("Produto.dat","r");
 	int pos, aux;
 	
 	clrscr();
	printf("\n* * * Consulta de Produto * * *\n\n");
 	
 	if(Ptr == NULL)
 	{
 		printf("\nNão tem nenhum produto castrado!!!");
	}
	else
	{
		printf("\nDigite o codigo do Fornecedor: ");
		scanf("%d", &Reg.codForn);
		aux = Reg.codForn;
		pos = BuscaProdForn(Reg.codForn, Ptr);
		if(pos == -1){
			printf("\nCodigo do Fornecedor não encontrado!!!");
		}
		else
		{
			rewind(Ptr);
			fread(&Reg, sizeof(TpProduto), 1, Ptr);
			while(!feof(Ptr)){
				if(aux == Reg.codForn){
					printf("\nCodigo prod: %d", Reg.cod);
					printf("\nCodigo forn: %d", Reg.codForn);
					printf("\nPreço: R$ %2.f", Reg.preco);
					printf("\nNome: %s\n", Reg.nome);
				}
				fread(&Reg, sizeof(TpProduto), 1, Ptr);
			}
		}
	}
 	
 	fclose(Ptr);
 	getch();
 }
 
 //Relatorios
 
 
