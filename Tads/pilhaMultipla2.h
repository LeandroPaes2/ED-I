/*
PILHA MULTIPLA 

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

struct TpPilhaM{
	int TOPO1, TOPO2;
	char PILHA [MAXPILHA];
};

void Inicializar (TpPilhaM &PM){
	PM.TOPO1 = -1;
	PM.TOPO2 = MAXPILHA;
}

void PUSH (TpPilhaM &PM, int NP, char Elem){
	if(NP == 1)
		PM.PILHA[++PM.TOPO1] = Elem;
	else
		PM.PILHA[--PM.TOPO2] = Elem;
}

char POP (TpPilhaM &P, int NP){
	if(NP == 1)
		return PM.PILHA[P.TOPO1--];
	else
		return PM.PILHA[PM.TOPO2++]
}

char ElemTopo (TpPilhaM PM, int NP){
	if(NP == 1)
		return PM.PILHA[PM.TOPO1];
	else
		retunr PM.PILHA[PM.TOPO2]; 
}

char Cheia (int TOPO1, int TOPO2){
	return (TOPO1 + 1 == TOPO2);
}

char Vazia (int topo, int NP){
	if (NP == 1)
        return (topo == -1);
    else
        return (topo == MAXPILHA);
}

void Exibir (TpPilhaM PM, int NP){
	char elem;
    if (NP == 1) {
        while (PM.TOPO1 != -1) {
            elem = POP(PM, 1);
            printf("%c ", elem);
        }
    } else {
        while (PM.TOPO2 != MAXPILHA) {
            elem = POP(PM, 2);
            printf("%c ", elem);
        }
    }
    printf("\n");
}





