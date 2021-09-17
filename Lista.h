// Cabeçario de segurança

#ifndef LISTA_H
#define LISTA_H


typedef struct no No;

struct no{
    int numero;
    struct no *prox;
};

// Funções para manipulação da lista

No* cria_no();
No* add_no_inicial(No* Lista,int dado);
No* add_no_final(No *Lista,int dado);
void imprimir_lista(No* Lista);
void libera_Lista(No* Lista);


#endif