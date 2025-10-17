#include <stdio.h>
#include <conio2.h>

struct Torre
{
	int a[], b[], c[];	
	int TLa, TLb, TLc;
};


void desenho(int a[], int b[], int c[], Tam tam)
{
	int i;
	
	for(i = 1; i <= tam.a; i++)
	{
		gotoxy(4, 2+i);
		printf("%d", a[i-1]);
	}
	gotoxy(4, 6);
	printf("a");
	
	for(i = 1; i <= tam.b; i++)
	{
		gotoxy(8, 2+i);
		printf("%d", b[i-1]);
	}
	gotoxy(8, 6);
	printf("b");
	
	for(i = 1; i <= tam.c; i++)
	{
		gotoxy(12, 2+i);
		printf("%d", c[i-1]);
	}
	gotoxy(12, 6);
	printf("c");
	

}

void Regra(char ori, char des)
{
	if(ori == 'a' && des == 'b')
			Torre(a, b);
		else if(ori == 'a' && des == 'c')
			Torre(a, c);
		else if(ori == 'b' && des == 'a')
			Torre(b, a);
		else if(ori == 'b' && des == 'c')
			Torre(b, c);
		else if(ori == 'c' && des == 'b')
			Torre(c, b);
		else if(ori == 'c' && des == 'a')
			Torre(c, a);
		else
		{
			printf("\nErro");
			getch();
		}
}

int torre(int a[], int b[], int c[], Tam tam)
{
	if((sizeof(c)/sizeof(c[0])) == 3)
		return 1;
	else
	{
		char hasteO, hasteD;
		desenho(a, b, c, tam);
		
		gotoxy(4,8);
		printf("Escolha a haste (origem):");
		fflush(stdin);
		scanf("%c", &hasteO);
		
		gotoxy(4,9);
		printf("Escolha a haste (destido):");
		fflush(stdin);
		scanf("%c", &hasteD);
		
		Regra(hasteO, hasteD);
		return torre(a, b, c, tam);
	}
}

int main(void)
{
	int a[3] = {1, 2, 3}, b[0], c[0];
	Tam tam;
	tam.a = 3; tam.b = 0; tam.c = 0;
	
	
	torre(a, b, c, tam);
	printf("Finalizada a Torre de Hanoi");
	
	return 0;
}
