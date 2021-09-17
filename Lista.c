#ifndef LISTA_C
#define LISTA_C
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/* Criando a estrutura de um Lista encadeada */
struct no{
    int numero; /* Dado a ser armazenado */
    struct no *prox; /* ponteiro para o próximo nó */
};

No* cria_no(){
    //Alocando o espaço na memória para o nó da lista
    No *novo = malloc(sizeof(No));
    return novo;
}

/* Inserindo valor no Começo da lista encadeada */
No* add_no_inicial(No* Lista,int dado){
    No* novo_no = cria_no();/* Chama a função para criar um novo nó*/
    novo_no -> numero = dado;  /* Novo nó recebe o dado a ser armazenado*/

    if(Lista == NULL){ /* Verifica se a lista está vazia */
        Lista = novo_no;/* Lista aponta pro nó */
        novo_no -> prox = NULL; /* O ponteiro para o proximo nó recebe NULL*/
    }

    else{
        novo_no -> prox = Lista; /* O ponteiro para o proximo nó recebe Lista*/
        Lista = novo_no; /* Lista aponta pro nó */
    }
    return Lista;
}

/* Inserindo valor no final da lista encadeada */
No* add_no_final(No *Lista,int dado){
    No *no = cria_no(); /* chama a função para criar um nó */
    no -> numero = dado; /* nó recebe o dado para armazenar */

    if(Lista == NULL){ /* Verifica se lista está vazia */
        no -> prox = NULL;/* O ponteiro aponta para NULL */
        Lista = no; /* lista recebe nó */
    }
    else{
        No* aux = Lista;

        while(aux -> prox != NULL){/* verifica se a aux chegou ao fim se não roda o trecho de código abaixo*/
            aux = aux -> prox; /*auxiliar recebe o ponteiro para o poximo*/
        }
        no -> prox = NULL;/* O ponteiro para o proximo aponta para NULL*/
        aux -> prox = no; /* O ponteiro começa a apontar para o nó */
    }
    return Lista;

}

/* Função para imprimir todos os elementos da lista */
void imprimir_lista(No* Lista){
    No *aux  = Lista; /* criar um ponteiro auxiliar que recebe Lista */

    while(aux != NULL){ /* verifica se a lista chegou ao fim se não roda o trecho de código abaixo*/
        printf("%d",aux -> numero); /* imprime o dado armazenado */
        printf("\n");/* pula linha */
        aux = aux->prox;/* auxiliar recebe o ponteiro do proximo nó */
    }
}

/* Função que libera memória alocada */
void libera_Lista(No* Lista){
    No *aux  = Lista; /* aux recebe Lista */

    while(aux != NULL){ /* Verifica se aux é diferente de NULL */
        free(aux);/* Libera o espaço alocado */
        Lista = aux->prox; /* Lista recebe o próximo nó */
    }
}

#endif