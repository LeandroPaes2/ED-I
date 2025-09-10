#define Max 10

struct PilhaM
{
	int TOPO1, TOPO2, pilha[Max];
};

void inicializar(PilhaM &PM)
{
	PM.TOPO1 = -1;
	PM.TOPO2= Max;
}

void PUSH(PilhaM &PM, int elem, int NP)
{
	if(NP==1)
		PM.pilha[++PM.TOPO1] = elem;
	else
		PM.pilha[--PM.TOPO2] = elem;	
}

int POP(PilhaM &PM, int NP)
{
	if(NP == 1)
		return PM.pilha[PM.TOPO1--];
	else
		return PM.pilha[PM.TOPO2++];
}

char Vazia(int topo, int NP)
{
	if(NP == 1)
		return topo == -1;
	else
		return topo == Max;
}

char Cheia(int topo1, int topo2)
{
	return topo1 == topo2 - 1;
}

int ElementoTopo(PilhaM PM, int NP)
{
	if(NP == 1)
		return PM.pilha[PM.TOPO1];
	else
		return PM.pilha[PM.TOPO2];
}

void Exibir(PilhaM PM, int NP)
{
	if(NP == 1)
	{
		while(!Vazia(PM.TOPO1, NP))
			printf("%d\n",POP(PM, NP));
	}
	else
	{
		while(!Vazia(PM.TOPO2, NP))
			printf("%d\n",POP(PM, NP));
	}

}
