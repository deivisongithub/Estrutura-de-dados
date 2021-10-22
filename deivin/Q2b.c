//Aluno: Deivison rodrigues jordão

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    char dado;
    struct no *proximo;
}No;

typedef struct Fila{
    No *inicio;
    No *Fim;
}Fila;

void create_Fila(Fila *f){
    f->inicio = NULL;
    f->Fim = NULL;
}


void push(char dado_usuario,Fila *f){
    No *ptr = malloc(sizeof(No));
    if(ptr == NULL){
        printf("Erro ao alocar memoria \n");
        return;
    }
    else{

        ptr->dado = dado_usuario;
        ptr->proximo = NULL;

        if(f->inicio == NULL){
            f->inicio = ptr;
        }
        else{
            f->Fim->proximo = ptr;
        }
        f->Fim = ptr;
        return;
    }
}

char pop(Fila *f){

    No *ptr = f->inicio;
    char dado_armazenado;

    if(ptr != NULL){
        f->inicio = ptr -> proximo;
        ptr->proximo = NULL;
        dado_armazenado = ptr->dado;
        free(ptr);
        if(f->inicio == NULL){
            f->Fim = NULL;
        }
        return dado_armazenado;
    }
    else{
        printf("Fila esta vazia \n");
    }
}

void print_Fila(Fila *f){
    No *ptr = f->inicio;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("%c ",ptr->dado);
            ptr = ptr->proximo; 
        }
    }
    else{
        printf("Fila esta vazia \n");
        return;
    }
}

void Verifica_Fila(Fila *f){
    if(f->inicio == NULL){
        printf("\nFila esta vazia \n");
    }
    else{
        printf("\nFila nao esta vazia \n");
    }
}

void Libera_fila(Fila *f){
    while (f->inicio != NULL){
        pop(f);
    }
    free(f);
    
}
/*
int size_Fila(Fila *f){
    int count = 0;
    No aux
    while (f->inicio != NULL){
        count++;
        printf("a");
    }
    return count;
}
*/

char main(void){
    
    Fila *f1 = malloc(sizeof(Fila));
    
    if(f1 == NULL){
        printf("Erro de alocacao. \n");
        exit(-1);
    }
    else{

        create_Fila(f1);

        push('A',f1);
        push('B',f1);
        push('C',f1);
        print_Fila(f1);

        Verifica_Fila(f1);

        Libera_fila(f1);
/*
        printf("\ntestando pop: %c \n",pop(f1));
        printf("testando pop: %c \n",pop(f1));
        printf("testando pop: %c \n",pop(f1));
*/
        Verifica_Fila(f1);
    }
}