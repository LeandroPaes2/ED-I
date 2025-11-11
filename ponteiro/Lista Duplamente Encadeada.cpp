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
	{
		printf("%d ", lista->info);
		Exibir(lista->prox);
	}
		
}

void ExibirDecres(TpPont *lista)
{
	TpPont *p = lista;
	while(p != NULL && p->prox != NULL)
	{
		p = p->prox;
	}
	
	while(p != NULL)
	{
		printf("%d ", p->info);
		p = p->ant;
	}
}

TpPont *Excluir(TpPont *lista, int valor)
{
	TpPont *p = lista;
	
	while(p != NULL && valor != p->info)
	{
		p = p->prox;
	}
	
	if(p == NULL)
	{
		printf("\nElemento nao encontrdo");
		getch();
		return lista;
	}
	
	if(p->ant == NULL)
	{
		lista = lista->prox;
		if(lista != NULL)
			lista->ant = NULL;
		delete(p);
	}
	else if(p->prox != NULL)
	{
		p->ant->prox = p->prox;
		p->prox->ant = p->ant;
	}
	else
	{
		p->ant->prox = NULL;	
	}
	
	delete(p);
	return lista;
}

TpPont *OrdenaCres(TpPont *lista, TpPont *caixa, int valor)
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
	printf("Digite:\n");
	scanf("%d", &num);
	while(num != 0)
	{
		caixa = NovaCaixa(num);
		
		lista = OrdenaCres(lista, caixa, num);
		
		scanf("%d", &num);
	}
	
	
	
	return lista;
}

void Busca(TpPont *lista, int valor)
{
	int nao = 0;
	while(lista != NULL)
	{
		if(valor == lista->info)
		{
			printf("\nValor encontrado!");
			nao = 1;
		}	
		lista = lista->prox;
	}
	
	if(nao == 0)
		printf("\nValor nao encontrado!");
}

int main(void)
{
	TpPont *lista = NULL;
	int num;
	
	lista = Inserir(lista);
	
	printf("\nExcluir: ");
	scanf("%d", &num);
	lista = Excluir(lista, num);
	
	printf("\n");
	Exibir(lista);
	printf("\n");
	ExibirDecres(lista);
	
	printf("\nBusca: ");
	scanf("%d", &num);
	Busca(lista, num);
	
	return 0;
}
