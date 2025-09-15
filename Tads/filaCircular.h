/*
FILA CIRCULAR
	=> com inicio variavel

operações associadas
	void Inicializar (TpFilaC &FC)
	void PUSH (TpFilaC &FC, TpElemento Elem)
	char POP (TpFilaC &FC)
	char ElemInicio (TpFilaC FC)
	char ElemFim (TpFilaC FC)
	char Vazia (int FIM)
	char Cheia (int FIM)
	void Exibir (TpFilaC FC)
*/

#define MAXFILA 10

struct TpFilaC {
	int INICIO;
	int FIM;
	int TAM;
	char FILA[MAXFILA];
};

void Inicializar(TpFilaC &FC) {
	FC.TAM = 0;
	FC.INICIO = 0;
	FC.FIM = -1;
}

void PUSH(TpFilaC &FC, char Elem) {
	if (FC.TAM == MAXFILA) {
		printf("Erro: fila cheia.\n");
		return;
	}
	if (FC.FIM == MAXFILA - 1)
		FC.FIM = -1;
	FC.FILA[++FC.FIM] = Elem;
	FC.TAM++;
}

char POP(TpFilaC &FC) {
	if (FC.TAM > 0) {
		char aux = FC.FILA[FC.INICIO];
		FC.INICIO = (FC.INICIO + 1) % MAXFILA;
		FC.TAM--;
		return aux;
	}
	printf("Erro: fila vazia.\n");
	return '\0';
}

char ElemInicio(TpFilaC FC) {
	return FC.FILA[FC.INICIO];
}

char ElemFim(TpFilaC FC) {
	return FC.FILA[FC.FIM];
}

char Vazia(TpFilaC FC) {
	return FC.TAM == 0;
}

char Cheia(TpFilaC FC) {
	return FC.TAM == MAXFILA;
}

void Exibir(TpFilaC FC) {
	if (FC.TAM > 0) {
		printf("Fila: ");
		int i = FC.INICIO;
		for (int cont = 0; cont < FC.TAM; cont++) {
			printf("%c ", FC.FILA[i]);
			i = (i + 1) % MAXFILA;
		}
		printf("\n");
	} else {
		printf("Fila vazia.\n");
	}
}
