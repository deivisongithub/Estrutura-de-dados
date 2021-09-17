#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


No* cria_no(){
    No *novo = malloc(sizeof(No));
    return novo;
}

No* add_no_inicial(No* Lista,int dado){
    No* novo_no = cria_no();
    novo_no -> numero = dado;

    if(Lista == NULL){
        Lista = novo_no;
        novo_no -> prox = NULL;
    }

    else{
        novo_no -> prox = Lista;
        Lista = novo_no;
    }
}

No* add_no_final(No *Lista,int dado){
    No *no = cria_no();
    no -> numero = dado;

    if(Lista == NULL){
        no -> prox = NULL;
        Lista = no;
    }
    else{
        No* aux = Lista;

        while(aux -> prox != NULL){
            aux = aux -> prox;
        }
        no -> prox = NULL;
        aux -> prox = no;
    }
    return Lista;

}


void imprimir_lista(No* Lista){
    No *aux  = Lista;

    while(aux != NULL){
        printf("%d",aux -> numero);
        printf("\n");
        aux = aux->prox;
    }
}

void libera_Lista(No* Lista){
    No *aux  = Lista;

    while(aux != NULL){
        free(aux);
        Lista = aux->prox;
    }
}