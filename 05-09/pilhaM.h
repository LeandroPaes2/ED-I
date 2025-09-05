struct pilhaM
{
	int topo1,topo2,pilha[TF];
}

void inicializar(pilhaM &p)
{
	p.topo1=-1;
	p.topo2=TF;
}

char cheia(pilhaM p, int qual)
{
	return p.topo1+1==p.topo2;
}

char vazia(pilhaM p,int qual)
{
	if(qual==1)
		return p.topo1==-1;
	return p.topo2==TF-1;
}

void inserir(pilhaM &p, int qual,int elem)
{
	if(qual==1)
		p.pilha[++p.topo1]=elem;
	else
		p.pilha[--p.topo1]=elem;	
}

int retirar(pilhaM &p,int qual)
{
	if(qual==1)
		return p.pilha[p.topo1--];
	return p.pilha[p.topo2++];
}

void exibir(pilhaM p,int qual)
{
	if(qual==1)
		{
			while(!vazia(p,qual))
				printf("%d\n",retirar(p,1))
		}
	else
		{
			while(!vazia(p,qual))
				printf("%d\n",retirar(p,2))
		}
	
}
