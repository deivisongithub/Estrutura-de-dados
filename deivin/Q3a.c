#include <stdio.h>

int Max_valor(int array[],int size){              
    int maior = array[0];                         // 1(atribuição)
    for(int i=0;i < size;i++){                    // 1(iniciação do i)  + n(comparações) + n(incrementos de i)
        if(maior < array[i]){                     // n(Expressão if)
            maior = array[i];                     // n(pior caso de atribuições)
        }                                         // logo,1+1+n+n+n+n
    }                                             // f(n) = 4n+2
    return maior;
}                                                 //Theta = Theta(n) pois 3 e 4 são constantes
int main(){                                       //Big O =  
    int lista[10]={20,1,2,3,44,5,6,9,15,19};      //Omega = 
    printf("%d",Max_valor(lista,10));
    return 0;
}