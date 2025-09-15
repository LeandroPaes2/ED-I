/*
TAD FILA 

operações associadas
	void Inicializar (TpFila &F)
	void PUSH (TpFila &F, char Elem)
	char POP (TpFila &F)
	char ElemInicio (TpFila F)
	char ElemFim (TpFila F)
	char Vazia (int fim)
	char Cheia (int fim)
	void Exibir (TpFila F)
*/

#define MAXFILA 10


struct TpFila {
	int FIM;
	char FILA[MAXFILA];
};

void Inicializar(TpFila &F){
	F.FIM = -1;
}

void PUSH(TpFila &F, char Elem){
	if (!Cheia(F.FIM))
		F.FILA[++F.FIM] = Elem;
}

char POP(TpFila &F){
	if (!Vazia(F.FIM)) {	
		char ant = F.FILA[0];
		for(int i = 0; i < F.FIM; i++)
			F.FILA[i] = F.FILA[i+1];
		F.FIM--;
		return ant;
	}
}

char ElemInicio(TpFila F){
	return F.FILA[0];
}

char ElemFim(TpFila F){
	return F.FILA[F.FIM];
}

char Vazia(int FIM){
	return FIM == -1;
}

char Cheia(int FIM){
	return FIM == MAXFILA - 1;
}

void Exibir(TpFila F){
	if (Vazia(F.FIM)) {
		printf("Fila vazia.\n");
		return;
	}
	
	for(int i = 0; i <= F.FIM; i++)
		printf("%c ", F.FILA[i]);
	
	printf("\n");
}
