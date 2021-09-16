#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{                      //Estrutura que representa o elemento da lista
    int dado;                       //Dado a ser armazenado
    struct lista *prox;             //Ponteira que aponta para o proximo elemento
};

struct lista *aloca(){                      //Função para alocação na memória
    return malloc(sizeof(struct lista));
}

void add_elemento(struct lista *prim){      //Função para adicionar um novo elemento a lista,recebe
    struct lista *auxiliar,*novo_elemento;  //como parâmetro o primeito elemento que só aponta para
                                            //o verdadeiro primeiro elemento ou nó

    auxiliar = prim;

    while(auxiliar -> prox != NULL){
        auxiliar = auxiliar -> prox;
    }

    novo_elemento = aloca();

    printf("Digite o valor do novo elemento: ");
    scanf("%d",&novo_elemento -> dado);             //coletando o dado que será armazenado na lista

    novo_elemento -> prox = NULL;                   // "Aterrando" o novo elemento

    auxiliar -> prox = novo_elemento;               //O ponteiro prox do auxiliar recebe o novo elemento


}

void imprimir_lista(struct lista p)
{
    printf("\n");
    while(p.prox !=NULL)
    {
        printf("%d",p -> dado);
        printf("\n");
        p = p -> prox;
    }
}

void libera_Lista(struct lista p)
{
    struct lista n;
    while(p.prox!=NULL)
    {
        n=p->prox;
        free(p);
        p=n;
    }
}


int main(void){

    struct lista Lista_1;   //inicializando a lista
    Lista_1.prox = NULL;    //"Aterrando a lista"
 
    return 0;
}