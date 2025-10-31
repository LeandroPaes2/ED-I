#include <stdio.h>

struct TpPont
{
	int info;
	TpPont *ant, *prox;	
};

TpPont *NovaCaixa(int valor)
{
	TpPont *no;
	no = new TpPont;
	no->info = valor;
	no->ant = NULL;
	no->prox = NULL;
	
	return no;
}

void Exibir(TpPont *lista)
{
	if(lista != NULL)
		printf("\n%d", lista->info);
	Exibir(lista->prox);
}

TpPont *Ordena(TpPont *lista, TpPont *caixa, int valor)
{
	
	TpPont *p = lista;
	TpPont *ant = NULL;
	
	while(p != NULL && valor > p->info)
	{
		ant = p;
		p = p->prox;
	}
	
	if(ant == NULL)
	{
		caixa->prox = lista;
		
		if(lista != NULL)
			lista->ant = caixa;
			
		lista = caixa;
	}
	else
	{
		caixa->prox = p;
		caixa->ant = ant;
		ant->prox = caixa;
		
		if(p != NULL)
			p->ant = caixa;
	}
	return lista;
}

TpPont *Inserir(TpPont *lista)
{
	TpPont *caixa;
	int num;
	
	
	printf("Digite: ");
	scanf("%d", &num);
	while(num != 0)
	{
		caixa = NovaCaixa(num);
		//caixa->prox = lista;
		
		
		
		lista = Ordena(lista, caixa, num);
		
		//lista = caixa;
		
		scanf("%d", &num);
	}
	
	Exibir(lista);
	
	return lista;
}

int main(void)
{
	TpPont *lista = NULL;
	
	lista = Inserir(lista);
	
	return 0;
}
