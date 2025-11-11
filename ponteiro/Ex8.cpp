#include <stdio.h>
#include <string.h>
#include <conio2.h>

struct TpPont
{
	int chave;
	char nome[20];
	TpPont *ant, *prox;
};

TpPont *NovoNo(int valor, char nom[20])
{
	TpPont *no;
	no = new TpPont;
	no->chave = valor;
	strcpy(no->nome, nom);
	no->ant = NULL;
	no->prox = NULL;	
	
	return no;
}

TpPont *Inserir(TpPont *lista)
{
	TpPont *caixa;
	int num;
	char nome[20];
	printf("\n* * Inserir * *\n");
	
	printf("\nChave: ");
	scanf("%d", &num);
	
	while(num != 0)
	{
		printf("Nome: ");
		fflush(stdin); gets(nome);
		caixa = NovoNo(num, nome);
		caixa->prox = lista;
			if(lista != NULL)
				lista->ant = NULL;
		lista = caixa;
		
		printf("\nChave: ");
		scanf("%d", &num);
	}
	
	
	return lista;
}

void Exibir(TpPont *lista)
{
	if(lista != NULL)
	{
		printf("\nChave: %d\nNome: %s", lista->chave, lista->nome);
		Exibir(lista->prox);
	}
}

void Buscar(TpPont *lista, int valor)
{
	int nao = 0;
	
	while(lista != NULL)
	{
		if(valor == lista->chave)
		{
			printf("Nome: %s", lista->nome);
			nao = 1;
		}
		lista = lista->prox;
	}
	
	if(nao == 0)
		printf("\nChave nao encontrada");
}

int main(void)
{
	TpPont *lista = NULL;
	int num;
	lista = Inserir(lista);
	
	clrscr();
	printf("\n* * Chaves * *\n");
	Exibir(lista);
	
	printf("\n\nDigite a chave: ");
	scanf("%d", &num);
	Buscar(lista, num);
	
	return 0;	
}
