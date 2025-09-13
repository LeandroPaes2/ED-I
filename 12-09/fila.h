/*
FILA

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



struct TpFila{
	int fim;
	char fila[MAXFILA];
};

void Inicializa(TpFila &F){
	f.fim = -1;
}

void vazia(int fim){
	return fim == -1;
}

void Cheia(int fim){
	return fim == MAXFILA - 1;
}

void Insere (TpFila &f, char elem){
	f.fila[++f.fim] = elem;
}

char Retira (TpFila &f){
	int i;
	char elem = f.fila[0];
	for(i=0; i<f.fim; i++)
		f.fila[i] = f.fila[i+1];
	f.fim--;
	return elem;
}

char ElemInicio(TpFila &f){
	return f.fila[0];
}

char ElemFim(TpFila &f){
	return f.fila[f.fim];
}

void Exibir(TpFila f){
	while(!Vazia(f.fim))
		printf("\n%c", Retira(f));
	getch();
}








