#include <stdio.h>
#include <stdlib.h>


//Criação do nó
typedef struct No{
   char dado;
   struct  No *prox;
}No;

//Criação da Pilha
typedef struct Pilha {
   No *topo;
}Pilha;

//Inicialização da Pilha
void iniciaPilha(Pilha *p) {
   p->topo = NULL;
}

//EmPilhamento
void empilhamento(char dado, Pilha *p){
   //casting
   No *ptr = (No*) malloc(sizeof(No));
   
   if(ptr == NULL){
      printf("Erro na alocação do nó! \n");
      return;
   }else{
      ptr->dado = dado;
      ptr->prox = p->topo;
      p->topo = ptr;
   }
} 

//Função de remoção do elemento da Pilha
char desempilhamento(Pilha *p){
   No* ptr = p->topo;
   char dado;
   if(ptr == NULL){
      printf("A Pilha encontra-se vazia.\n");
      return 0;
   }else{
      p->topo = ptr->prox;
      ptr->prox = NULL;
      dado = ptr->dado;
      free(ptr);
      return dado;
   }
}

//Impressão
void imprimePilha(Pilha *p){
   No *ptr = p->topo;
   if(ptr == NULL){
      printf("A Pilha encontra-se vazia.\n");
      return;
   }else{
      while(ptr != NULL){
         printf("%d ", ptr->dado);
         ptr = ptr->prox;
      }
       printf("\n");
   }
}

int balanceamento(char dados[], int tamanho){
   Pilha *pBalanc = (Pilha*) malloc(sizeof(Pilha));
   iniciaPilha(pBalanc);
   char verifElement;
   if(pBalanc == NULL){
      printf("Erro na alocação da pilha! \n");
      exit(0);
   } else {
      for(int i = 0; i < tamanho; i++){
         if(dados[i] == '{' || dados[i] == '(' || dados[i] == '['){
            empilhamento(dados[i], pBalanc);
         } else if (dados[i] == '}' || dados[i] == ')' || dados[i] == ']'){
            verifElement = desempilhamento(pBalanc);
            if(verifElement == '(' && dados[i] == ')'){
               continue;
            }else if(verifElement == '{' && dados[i] == '}'){
               continue;
            }else if(verifElement == '[' && dados[i] == ']'){
               continue;
            }else{
               printf("O array não está balanceado.\n");
               return 0;
            }
         }
      }
      printf("O array está balanceado.\n");
      return 1;
   }
}

int main(void){
   Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
   char dados[6] = {')', '(', ')', '{', '}', ')'};
   
   if(p1 == NULL){
      printf("Erro na alocação da pilha! \n");
      exit(0);
   } else {
      iniciaPilha(p1);
      empilhamento(45, p1);
      empilhamento(12, p1);
      imprimePilha(p1);
      balanceamento(dados, 6);
   }

   return 0;
}