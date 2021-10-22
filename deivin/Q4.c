#include <stdio.h>
#include <stdlib.h>
 
//Funcao recursiva para calcular MDC de dois números usando algoritmo de Euclides
int MDC(int a, int b){
    if(b == 0) return a;
    return MDC(b, a % b);
}

int main(void){
    printf("%d\n",MDC(195,150));
    printf("%d\n",MDC(195,-150));
    printf("%d\n",MDC(195,0));
    return 0;
}