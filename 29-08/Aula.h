#define MAXPILHA 2000

struct TpPilha{
	int TOPO, pilha[MAXPILHA];
};

void Inicializa ( TpPilha &p ){
	p.TOPO = -1;
}

void PUSH ( TpPilha &p, char elem ){
	p.pilha[++p.TOPO] = elem;
}

char POP ( TpPilha &p ){
	return p.pilha[p.TOPO--];
}

char ElementoTopo ( TpPilha p ){
	return p.pilha[p.TOPO];
}

int Cheia ( int topo ){
	return topo == MAXPILHA -1;
}

int Vazia ( int topo ){
	return topo == -1;
}

void Exibe (TpPilha p){
	printf("\nPilha:");
	while(!Vazia(p.TOPO))
		printf("\n%d", POP(p));
	getch();
}
