/*
TAD Pilha 

operações associadas
	void Inicializar (TpPilha &P)
	void PUSH (TpPilha &P, char Elem)
	char POP (TpPilha &P)
	char ElemTopo (TpPilha P)
	char Vazia (int topo)
	char Cheia (int topo)
	void Exibir (TpPilha P)
*/

#define MAXPILHA 10

struct TpPilha{
	int TOPO;
	char PILHA [MAXPILHA];
};

void Inicializar (TpPilha &P){
	P.TOPO = -1;	
}

void PUSH (TpPilha &P, char Elem){
	P.PILHA[++P.TOPO] = Elem;
}

char POP (TpPilha &P){
	returm P.PILHA[P.TOPO--];
}

char ElemTopo (TpPilha P){
	return P.PILHA[P.TOPO]; 
}

char Vazia (int topo){
	return TOPO = -1;
}

char Cheia (int topo){
	return TOPO == MAXPILHA -1;
}

void Exibir (TpPilha P){
	while(!Vazia(P.TOPO)){
		printf("\n%c", POP(P));
	}
}





