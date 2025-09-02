#define Max 3

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

void Exibir(TpPilha p1, TpPilha p2, TpPilha p3)
{
	int i = 3;
	clrscr();
	while(!Vazia(p1.TOPO))
	{
		gotoxy(4, i++);
		printf("%d", POP(p1));
	}
	gotoxy(4,6);
	printf("a");
	
	i = 3;
	while(!Vazia(p2.TOPO))
	{
		gotoxy(8, i++);
		printf("%d", POP(p2));
	}
	gotoxy(8,6);
	printf("b");
	
	i = 3;
	while(!Vazia(p3.TOPO))
	{
		gotoxy(12, i++);
		printf("%d", POP(p3));
	}
	gotoxy(12,6);
	printf("c");
	
	getch();
}

void Torre(TpPilha &p1, TpPilha &p2){
	
	if(p1.Pilha[p1.TOPO] < p2.Pilha[p2.TOPO] || Vazia(p2.TOPO))
	{
		PUSH(p2, POP(p1));
	}
}



