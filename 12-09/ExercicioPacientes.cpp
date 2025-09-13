/*
Utilizando o Arquivo Texto (Pacientes.txt) com os dados abaixo, implemente uma
Simulação de atendimento para cada Paciente.
Considere que o Médico "chama o próximo" Paciente, e o sistema deve indicar 
qual deve ser atendido no momento e definir (por sorteio) o tempo de atendimento
para este Paciente. O tempo de atendimento deve ser de 3-6 unidades de tempo (ut).

Considere que cada ut é uma iteração ocorrida no laço de repetição. O atendimento
deve ser finalizado, quando o usuário pressionar uma tecla ou quando os atendimentos
terminarem. Após, informar: quantos atendimentos ocorreram e qual foi o tempo médio
que o Paciente levou para ser atendido.

Arquivo texto com 100 linhas de dados de pacientes, onde cada linha contém os dados
separados por ponto-e-vírgula.

Os atributos de cada paciente são: Nome, ID (número de identificação), e Prioridade.
*/

#include<stdio.h>
#include<string.h>
#include<conio2.h>
#include<ctype.h>
#include<stdlib.h>
#include <windows.h>

#include "ExercicioPacientes.h"

//Sleep();

void InserirPaciente(TpFila){
	TpPaciente pac;
	FILE *Ptr = fopen("Pacientes.txt", "r");
	fscanf(Ptr,"%[^;];%d;%d", pac.nome, pac.id, pac.prior);
	while(!feof(ptr)){
		Insere(f, pac);
		fscanf(Ptr,"%[^;];%d;%d", pac.nome, pac.id, pac.prior);
	}
	fclose(arq);
}

//

void Atendimento(){
	TpPaciente pac;
	FILE *Ptr = fopen("Pacientes.txt", "r");
	int contF = 0, contA = 0, ale;
	do{
		ale = (rand() % 4) + 3;
		if(contF == 0){
			fscanf(Ptr,"%[^;];%d;%d", pac.nome, pac.id, pac.prior);
			Insere(f, pac);
		}		

		if(contF == 3)
			contF = 0;
		else
			contF++;
		
		if(contF == ale){
			contA = 0;
			Retira(f);
		}
		else
			contA++;
			
		Sleep(ut*1000);	
	}while(!feof(ptr) || !kbhit());
	
}
	


int main(){
	TpFila f;
}
