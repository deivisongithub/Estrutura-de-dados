#include <stdio.h>
#include <stdlib.h>
 
//Funcao recursiva para calcular MDC de dois números usando algoritmo de Euclides
int mdcRecursive(int a, int b){
    if(b == 0) return a;
    return mdcRecursive(b, a % b);
}
int main(void){
    printf("%d",mdcRecursive(195,150));
    return 0;
}