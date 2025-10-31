#include <stdio.h>
#include <conio2.h>

struct TpPont
{
	int info; // valor que armazena
	TpPont *prox; // ponteiro para o proximo nó
};

int Busca(TpPont *lista, int valor)
{
	while(lista != NULL && valor != lista->info)
	{
		lista = lista->prox;
	}
	
	if(lista == NULL)
		return -1;

	return 0;
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
		printf("\nElemento nao encontrado!");
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

TpPont *Ordena(TpPont *lista, TpPont *caixa, TpPont *ant, int valor)
{
	
	TpPont *p = lista;
	
	while(p != NULL && valor > p->info)
	{
		ant = p;
		p = p->prox;
	}
	
	if(ant == NULL)
	{
		caixa->prox = lista;
        lista = caixa;
	}
	else
	{
        ant->prox = caixa;
        caixa->prox = p;
    }
	return lista;
}

void Exibir(TpPont *lista)
{
	if(lista != NULL)
		printf("\n%d", lista->info);
	Exibir(lista->prox);
}

TpPont *NovoNo(int valor)
{	
	TpPont *no;
	no = new TpPont;
	no->info = valor;
	no->prox = NULL;
	
	return no;
}

TpPont *Inserir(TpPont *lista)
{
	TpPont *caixa, *ant;
	int num;
	
	scanf("%d", &num);
	while(num != 0)
	{
		caixa = NovoNo(num);
		//caixa->prox = lista;
		//lista = caixa;
		
		lista = Ordena(lista, caixa, ant, num);
		
		scanf("%d", &num);
	}
	
	
	return lista;
}

int main(void)
{
	int num;
	
	TpPont *lista = NULL;
	
	lista = Inserir(lista);
	
	TpPont *aux = lista;
	
	printf("Primeiro elemento: %d\n", aux->info);
	
	while(aux != NULL)
	{
		if(aux->prox == NULL)
			printf("Ultimo elemento: %d\n", aux->info);
		aux = aux->prox;
	}

	printf("Excluir algum elemento: ");
	scanf("%d", &num);
	Excluir(lista, num);

	printf("\nAchar algum elemento: ");
	scanf("%d", &num);
	int acha = Busca(lista, num);

	if(acha == -1)
		printf("Nao encontrou");
	else
		printf("Encontrou");

	printf("\nLista Ordenada:");
	Exibir(lista);
	
	
	getch();
	return 0;
	
}
