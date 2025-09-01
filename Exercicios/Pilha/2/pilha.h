#define Max 8

struct TpPilha{
	int TOPO, Pilha[Max];
}; 


void Inicializa(TpPilha &p)
{
	p.TOPO = -1;
}

void PUSH(TpPilha &p, int elem)
{
	p.Pilha[++p.TOPO] = elem;
}

int POP(TpPilha &p)
{
	return p.Pilha[p.TOPO--];
}

char Vazia(int topo)
{
	return topo == -1;
}

char Cheia(int topo)
{
	return topo == Max - 1;
}

int ElementoTopo(TpPilha p)
{
	return p.Pilha[p.TOPO];
}

void Exibir(TpPilha p)
{
	while(!Vazia(p.TOPO))
		printf("\n%d", POP(p));
	getch();
}

void ExcluirPos(TpPilha &p, int num)
{
	int aux[Max], i = -1, j;
	while(!Vazia(p.TOPO))
	{
		j = POP(p);
		if(j != num)
		{
			aux[++i] = j;
		}

	}
	
	while(i >= 0)
	{
		PUSH(p, aux[i--]);
	}
	
	Exibir(p);
}



