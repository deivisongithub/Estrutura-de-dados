#include <stdio.h>
#include "Lista.h"

int main(){
    No *Lista = NULL;
    Lista = add_no_inicial(Lista,10);
    add_no_final(Lista,11);
    imprimir_lista(Lista);
    libera_Lista(Lista);

    return 0;
}