#define MAXFILA 10

struct TpPessoa{
	int cod,prioridade;
};

struct TpFilaCircular{
	int fim,inicio,cont;
	TpPessoa pessoas[MAXFILA];
};

void InicializarFila(TpFilaCircular &fila){
	fila.fim=-1;
	fila.inicio=0;
	fila.cont=0;
}

OrdenaFilaPrioridade(TpFilaCircular &fila){
	int i,j, valid=0;
	TpPessoa aux1,aux2,aux3;
	for(i=0,j=fila.fim;i<cont-1 && valid==0;i++,j--)
	{
		if(j-1<0)
			if(fila.pessoas[j].prioridade<fila.pessoas[MAXFILA-1].prioridade)
			{
				aux=fila.pessoas[j];
				fila.pessoas[j]=fila.pessoas[MAXFILA-1];
				fila.pessoas[MAXFILA-1]=aux;
				j=MAXFILA;
			}
			else
				valid=1;
		else
			if(fila.pessoas[j].prioridade<fila.pessoas[j-1].prioridade)
			{
				aux= fila.pessoas[j];
				fila.pessoas[j]=fila.pessoas[j-1];
				fila.pessoas[j-1]=aux;	
			}
			else 
				valid=1;
	}
}

void PushFila(TpFilaCircular &fila, TpPessoa pessoa){
	if(++fila.fim>MAXFILA-1){
		fila.fim=-1;
		fila.pessoas[fila.fim]=pessoa;
		cont++;
		OrdenaFilaPrioridade(fila);
	}
	else
	{
		fila.pessoas[fila.fim]=pessoa;
		OrdenaFilaPrioridade(fila);
	}
}

struct PopFila(TpFilaCircular &fila){
	TpPessoa pessoa;
	pessoa= fila.pessoas[fila.inicio];
	cont--;
	if(cont==0)
		InicializarFila(fila);
	else
	{
		if(++fila.inicio>MAXFILA-1)
			fila.inicio=0;
	}
	return pessoa;
}

struct ElementoInicio(TpFilaCircular fila){
	return fila.pessoas[fila.inicio];
}


struct ElementoFim(TpFilaCircular fila){
	return Fila.pessoas[fila.fim];
}

char FilaVazia(TpFilaCircular fila){
	return fila.cont==0;
}

char FilaCheia(TpFilaCircular fila){
	return fila.cont==MAXFILA;
}

void ExibirFila(TpFilaCircular fila){
	TpPessoa pessoa;
	while(!FilaVazia(fila)){
		pessoa=PopFila(fila);
		printf("Cod: %d - %d\n",pessoa.cod,pessoa.prioridade);
	}
}

