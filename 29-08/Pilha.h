/*
	ESTRUTURA DE DADOS COM ACESSO DO TIPO PILHA
		-> conceito "LIFO"
					->last in first out
		-> também chamado de PUSH-POP por acessar apenas uma extremidade denominada de TOPO
		-> aplicações:
				- compilaores
				- sistemas operacionais 
				- cálculo de expressões
				- recursividade
		->Operações Associadas 
				- Inicializar 
				- PUSH -> inserir um elemento
				- POP -> retirar e retornar
				- acesso ao elemento do topo, retornando-o
				- verifica se pilha cheia 
				- verifica se pilha vazia
				- exibir pilha
				
*/
#define MAXPILHA 10

struct TpPilha{
	int TOPO, pilha[MAXPILHA];
};

void Inicializa ( TpPilha &p ){
	p.TOPO = -1;
}

void PUSH ( TpPilha &p, char elem ){
	p.pilha[++p.TOPO] = elem;
}

char POP ( TpPilha &p ){
	return p.pilha[p.TOPO--];
}

char ElementoTopo ( TpPilha p ){
	return p.pilha[p.TOPO];
}

int Cheia ( int topo ){
	return topo == MAXPILHA -1;
}

int Vazia ( int topo ){
	return topo == -1;
}

void Exibe (TpPilha p){
	printf("\nPilha:");
	while(!Vazia(p.TOPO))
		printf("\n%d", POP(p));
	getch();
}
