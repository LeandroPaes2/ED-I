/*
	FILA COM PRIORIDADE PACIENTES
	
		void InicializarTpFila &f);
		char Vazia(int fim);
		char Cheia(int fim);
		void Insere(TpFila &f, char elem);
		char Retira(TpFila &f);
		char ElemInicio(TpFila f);
		char ElemFim(TpFila f);
		void Exibir(TpFila f);
*/

#define MAXFILA 100


struct TpPaciente{
	char nome[50];
	int id, prior;		//(1-Urgente / 2-Médio / 3-Normal)
};

struct TpFilaP{
	int fim;
	TpPaciente fila[MAXFILA];
};

void Inicializa(TpFilaP &f){
	f.fim = -1;
}

int Vazia(int fim){
	return fim == -1;
}

int Cheia(int fim){
	return fim == MAXFILA - 1;
}

void Insere (TpFilaP &f, TpPaciente elem){
	int i = f.fim, j = f.fim;
	while(i>=0 && f.fila.[i] != elem.prior)
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
	TpPaciente elem = f.fila[0];
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
	TpPaciente elem; 
	while(!Vazia(f.fim)){
		elem = Retira(f);
		printf("\n%s, %d, %d\n",elem.nome,elem.id, elem.prior);
	}
		
	getch();
}
