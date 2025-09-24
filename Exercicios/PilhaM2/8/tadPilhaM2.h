#define TF 20

struct TpPilhaM2
{
	int topo[TF],base[TF];
	char pilha[TF];
};

void inicializar(TpPilhaM2 &pm,int qtdPilhas)
{
	int qtdElem = TF/qtdPilhas;
	for(int i=0;i<qtdPilhas;i++)
	{
		pm.base[i] = i*qtdElem;
		pm.topo[i] = pm.base[i]-1;	
	}
}
char PMvazia(TpPilhaM2 PM,int NP) //NP={0,1,2}
{
	return PM.topo[NP] < PM.base[NP];
}
char PMcheia(TpPilhaM2 PM,int NP)
{
	return PM.topo[NP] == PM.base[NP+1]-1 ;
}
char retirar(TpPilhaM2 &PM,int NP)
{
	return PM.pilha[PM.topo[NP]--];
}

void inserir(TpPilhaM2 &PM, char elem, int NP)
{
	PM.pilha[++PM.topo[NP]] = elem;
}

void exibir(TpPilhaM2 PM,int NP)
{
	while(!vazia(PM.topo,NP))
			printf("%c",pop(PM,NP));
}
