/*
PILHA MULTIPLA com 'N' pilhas
	
operações associadas
	void Inicializar (TpPilhaM &PM)
	void PUSH (TpPilhaM &PM, int NP, char Elem)
	char POP (TpPilhaM &P, int NP)
	char ElemTopo (TpPilhaM PM, int NP)
	char Vazia (int topo, int NP)
	char Cheia (int TOPO1, int TOPO2)
	void Exibir (TpPilhaM PM, int NP)
	
	*NP = numero da pilha
*/


#define MAXPILHA 10

struct TpPilhaM {
    int TOPO[MAXPILHA], BASE[MAXPILHA];
    char PILHA[MAXPILHA];
};

void Inicializar(struct TpPilhaM *PM, int qtdPilhas) {
    int i, qtdElem = MAXPILHA / qtdPilhas;
    for(i = 0; i < qtdPilhas; i++) {
        PM->BASE[i] = i * qtdElem;
        PM->TOPO[i] = PM->BASE[i] - 1;
    }
}

int Cheia(struct TpPilhaM *PM, int NP, int qtdPilhas) {
    if (NP == qtdPilhas - 1)
        return PM->TOPO[NP] == MAXPILHA - 1;
    else
        return PM->TOPO[NP] + 1 == PM->BASE[NP + 1];
}

int Vazia(struct TpPilhaM *PM, int NP) {
    return PM->TOPO[NP] < PM->BASE[NP];
}

void PUSH(struct TpPilhaM *PM, int NP, char Elem, int qtdPilhas) {
    if (!Cheia(PM, NP, qtdPilhas))
        PM->PILHA[++PM->TOPO[NP]] = Elem;
    else
        printf("Pilha %d cheia!\n", NP);
}

char POP(struct TpPilhaM *PM, int NP) {
    if (!Vazia(PM, NP))
        return PM->PILHA[PM->TOPO[NP]--];
    else {
        printf("Pilha %d vazia!\n", NP);
        return '\0';
    }
}

char ElemTopo(struct TpPilhaM *PM, int NP) {
    if (!Vazia(PM, NP))
        return PM->PILHA[PM->TOPO[NP]];
    else {
        printf("Pilha %d vazia!\n", NP);
        return '\0';
    }
}

void Exibir(struct TpPilhaM *PM, int NP) {
    if (Vazia(PM, NP)) {
        printf("Pilha %d vazia!\n", NP);
        return;
    }
    for (int i = PM->BASE[NP]; i <= PM->TOPO[NP]; i++) {
        printf("%c ", PM->PILHA[i]);
    }
    printf("\n");
}

