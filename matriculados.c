#include <stdio.h>
#include <stdlib.h>
#include "matriculados.h"
#include "aluno.h"


struct matriculados{
    int matricula;
    char nome[30];
    char sobrenome[30];
    struct matriculados* prox;
    Aluno* aluno;
};

Matriculados* comecar(){
    return NULL;
}

Matriculados* inserirM_inicio(Aluno* l, int mat){
    if((buscar_aluno(l->aluno, mat)) == 1){//Se a matricula existe na lista de cadastrados
        Matriculados* novo = (Matriculados*)malloc(sizeof(Matriculados));
        novo->matricula = l->matricula;
        strcpy(novo->nome, l->nome);
        strcpy(novo->sobrenome, l->sobrenome);
        novo->prox = l;
        return novo;
    }
    else{
        printf("Aluno nao cadastrado. Tente novamente.\n\n");
    }
}

void imprimirM(Matriculados* l) {
    Matriculados* p; /* variável auxiliar para percorrer a lista */
    for(p = l; p != NULL; p = p->prox)
        printf("%d\t\t\t%s\n",p->matricula, p->nome);
}







