#include <stdio.h>
#include <conio.h>


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

TpPont *Excluir(TpPont *lista, int valor)
{
	TpPont *p = lista;
	TpPont *ant = NULL;
	
	while(p != NULL && valor != p->info)
	{
			ant = p;
			p = p->prox;
	}
	if(p == NULL)
	{
		printf("\nElemento nao encontrdo");
		getch();
		return lista;
	}
	
	if(ant == NULL)
	{
		lista = lista->prox;
		delete(p);
	}
	else
	{
		ant->prox = p->prox;
		delete(p);
	}
	return lista;
}

TpPont *OrdenaCres(TpPont *lista, TpPont *caixa, int valor)
{
	
	TpPont *p = lista;
	TpPont *ant = NULL;
	
	while(p != NULL && valor > p->info)
	{
		caixa->ant = p;
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
		caixa->ant->prox = caixa;
		
		if(p != NULL)
			p->ant = caixa;
	}
	return lista;
}

TpPont *Inserir(TpPont *lista)
{
	TpPont *caixa;
	caixa->ant = NULL;
	int num;
	
	
	printf("Digite: ");
	scanf("%d", &num);
	while(num != 0)
	{
		caixa = NovaCaixa(num);
		//caixa->prox = lista;
		
		
		
		lista = OrdenaCres(lista, caixa, num);
		
		//lista = caixa;
		
		scanf("%d", &num);
	}
	
	
	
	return lista;
}

int main(void)
{
	TpPont *lista = NULL;
	int num;
	
	
	lista = Inserir(lista);
	
	printf("\nExcluir: ");
	scanf("%d", &num);
	lista = Excluir(lista, num);
	
	Exibir(lista);
	return 0;
}
