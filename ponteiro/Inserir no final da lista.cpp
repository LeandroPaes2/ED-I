#include <stdio.h>

struct TpPont
{
	int info;
	TpPont *prox;	
};

TpPont *NovoNo(int valor)
{
	TpPont *no;
	no = new TpPont;
	no->info = valor;
	no->prox = NULL;
	
	return no;
}

void Exibir(TpPont *lista)
{
	if(lista != NULL)
		printf("\n%d", lista->info);
	Exibir(lista->prox);
}

TpPont *Inserir(TpPont *lista)
{
	TpPont *caixa;
	int num;
	
	printf("Digite:\n");
	scanf("%d", &num);
	while(num != 0)
	{
		caixa = NovoNo(num);
		//caixa->prox = lista;
		//lista = caixa;
		
		if(lista == NULL)
	    {
	        lista = caixa;
	    }
	    else
	    {
	        TpPont *p = lista;
	        while(p->prox != NULL)
	        {
	            p = p->prox;
	        }
	        p->prox = caixa;
	    }
		
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
