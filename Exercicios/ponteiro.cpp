#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *proximo;
};

int main() {
    struct No *p;
	p = NULL;
	
	p = (struct No *) malloc(sizeof(struct No));
	p->valor = 42;
	p->proximo = NULL;
	printf("\np: %d", p);
	printf("\np->valor: %d", p->valor);
	printf("\np->proximo: %d", p->proximo);

    return 0;
}

