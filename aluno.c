#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"


struct aluno{
    int matricula;
    char nome[30];
    char sobrenome[30];
    struct aluno* prox;
};

Aluno* inicializar(){
    return NULL;
}

Aluno* inserir_inicio(Aluno* l, int mat, char n[], char s[]){
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    novo->matricula = mat;
    strcpy(novo->nome, n);
    strcpy(novo->sobrenome, s);
    novo->prox = l;
    return novo;
}

Aluno* inserir_final(Aluno* l, int mat, char n[], char s[]){
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    novo->matricula = mat;
    strcpy(novo->nome, n);
    strcpy(novo->sobrenome, s);
    novo->prox = NULL;

    if(l == NULL){
        return novo;
    }
    else{
        Aluno* ant;
        Aluno* p = l;
        while (p != NULL) {
            ant = p;
         			p = p->prox;
      		}
      		ant->prox = novo;
      		return l;
    }
}

int lista_vazia(Aluno* l){
    if(l==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int obterElemento(Aluno* l, int ind) {
    Aluno* p;	/* variável auxiliar para percorrer a lista */
    int i = -1;
    for(p = l; p != NULL; p = p->prox) {
        ++i;
        if(i == ind)
            return p->matricula;
    }
    printf("Matricula informada não existe na lista\n");
    exit(1);
}

int buscar_aluno(Aluno* l, int v) {
    int i = -1;
    Aluno* p;  /* variável auxiliar para percorrer a lista */
    for(p = l; p != NULL; p = p->prox) {
        ++i;
        if (p->matricula == v)
           return 1;
    }
    return -1; /* se não achou o elemento */
}

Aluno* remover(Aluno* l, int v) {
    Aluno* ant = NULL; /* ponteiro para elemento anterior */
    Aluno* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->matricula != v) {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if (p == NULL)
       return l; /* não achou: retorna lista original */
    if (ant == NULL) {
        l = p->prox;  /* retira elemento do inicio */
    }
    else {
        ant->prox = p->prox; /* retira elemento do meio da lista */
    }
    free(p);  /* desaloca a área de memória do elemento removido */
    return l;
}

void imprimir(Aluno* l) {
    Aluno* p; /* variável auxiliar para percorrer a lista */
    for(p = l; p != NULL; p = p->prox)
        printf("%d\t\t\t%s\n",p->matricula, p->nome);
}

/* função que retorna o tamanho da lista  */
int tamanho(Aluno* l) {
    Aluno* p;
    int tam = 0;
    for(p = l; p != NULL; p = p->prox)
        ++tam;
    return tam;
}

/* função para desalocar todo a área de memória ocupada pela lista */
void liberar(Aluno* l) {
    Aluno* p = l;
    while (p != NULL) {
        Aluno* t = p->prox; /* guarda referência para o próximo elemento */
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}



