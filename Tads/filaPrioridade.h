/*
FILA COM PRIORIDADE

operações associadas
	void Inicializar (TpFila &F)
	void PUSH (TpFila &F, TpElemento Elem)
	char POP (TpFila &F)
	char ElemInicio (TpFila F)
	char ElemFim (TpFila F)
	char Vazia (int fim)
	char Cheia (int fim)
	void Exibir (TpFila F)
*/

#define MAXFILA 10

struct TpElemento{
	int Prioridade;
	char Elemento[20];
};

struct TpFila {
	int FIM;
	TpElemento FILA[MAXFILA];
};

void Inicializar(TpFila &F){
	F.FIM = -1;
}

void PUSH(TpFila &F, TpElemento Elem){
	int i = F.FIM;
	if (!Cheia(F.FIM)){
		while (i >= 0 && F.FILA[i].Prioridade > Elem.Prioridade) {
			F.FILA[i + 1] = F.FILA[i];
			i--;
		}
		F.FILA[i + 1] = Elem;
		F.FIM++;
	}
}

char POP(TpFila &F){
	TpElemento aux;

	if (Vazia(F.FIM)) {
		printf("Erro: Fila vazia.\n");
		aux.Prioridade = -1;
		strcpy(aux.Elemento, "");
		return aux;
	}

	aux = F.FILA[0];
	for (int i = 0; i < F.FIM; i++) {
		F.FILA[i] = F.FILA[i + 1];
	}
	F.FIM--;
	return aux
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
	printf("Fila com prioridades:\n");
	for (int i = 0; i <= F.FIM; i++) {
		printf("Prioridade: %d | Elemento: %s\n", F.FILA[i].Prioridade, F.FILA[i].Elemento);
	}
	printf("\n");
}
