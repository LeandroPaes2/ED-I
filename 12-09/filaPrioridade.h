/*
	FILA COM PRIORIDADE
	
		void InicializarTpFila &f);
		char Vazia(int fim);
		char Cheia(int fim);
		void Insere(TpFila &f, char elem);
		char Retira(TpFila &f);
		char ElemInicio(TpFila f);
		char ElemFim(TpFila f);
		void Exibir(TpFila f);
*/

#define MAXFILA


struct TpElem{
	char info;
	char prior;
};

struct TpFilaP{
	int fim;
	TpElem fila[MAXFILA];
};

void Inicializa(TpFilaP &F){
	f.fim = -1;
}

void vazia(int fim){
	return fim == -1;
}

void Cheia(int fim){
	return fim == MAXFILA - 1;
}

void Insere (TpFilaP &f, TpElem elem){
	int i = f.fim, j = f.fim;
	while(i>=0 && f.fila.prior[i] != elem.prior)
		i--;
	if(f.fila.prior[i] == elem.prior){
		while(j>i){
			f.fila[j+1] = f.fila[j];
			j--;
		}
		f.fila[i] = elem;
	}
}

TpElem Retira (TpFilaP &f){
	int i;
	TpElem elem = f.fila[0];
	for(i=0; i<f.fim; i++)
		f.fila[i] = f.fila[i+1];
	f.fim--;
	return elem;
}

TpElem ElemInicio(TpFilaP &f){
	return f.fila[0];
}

TpElem ElemFim(TpFilaP &f){
	return f.fila[f.fim];
}

void Exibir(TpFilaP f){
	TpElem elem; 
	while(!Vazia(f.fim)){
		elem = Retira(f);
		printf("\n%c, %d\n",elem.info, elem.prior);
	}
		
	getch();
}
