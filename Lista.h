// Cabeçario de segurança

#ifndef LISTA_H
#define LISTA_H

/* Criando uma Lista com TAD */
typedef struct no No;

// Funções para manipulação da lista

/* Criando um nó da lista */
No* cria_no();
/* Adiciona um nó no inicío da lista */
No* add_no_inicial(No* Lista,int dado);
/* Adiciona um nó no final da lista */
No* add_no_final(No *Lista,int dado);
/* Imprime toda a lista */
void imprimir_lista(No* Lista);
/* libera todo o espaço que foi alocado para a lista */
void libera_Lista(No* Lista);


#endif