#include <stdio.h>
#include <stdlib.h>



typedef struct No{            //estrutura do no
   char dado;
   struct  No *proximo;
}No;


typedef struct Pilha {     //Estrutura da Pilha
   No *topo;
}Pilha;


void create_Pilha(Pilha *p) {   //Inicialização da Pilha
   p->topo = NULL;
}


void push(char dado, Pilha *p){                 //Adiciona um elemento na pilha

   No *ptr = (No*) malloc(sizeof(No));
   
   if(ptr == NULL){
      printf("Erro na alocacao \n");
      return;
   }else{
      ptr->dado = dado;
      ptr->proximo = p->topo;
      p->topo = ptr;
   }
} 


char pop(Pilha *p){           //Função de remoção do elemento da Pilha
   No* ptr = p->topo;
   char dado;
   if(ptr == NULL){
      printf("A Pilha esta vazia.\n");
      return 0;
   }else{
      p->topo = ptr->proximo;
      ptr->proximo = NULL;
      dado = ptr->dado;
      free(ptr);
      return dado;
   }
}


void Print_Pilha(Pilha *p){         //Imprime a pilha
   No *ptr = p->topo;
   if(ptr == NULL){
      printf("A Pilha esta vazia.\n");
      return;
   }else{
      while(ptr != NULL){
         printf("%d ", ptr->dado);
         ptr = ptr->proximo;
      }
       printf("\n");
   }
}

void Verifica_Pilha(Pilha *p){               //Verifica se a pilha esta vazia ou não
   if(p->topo == NULL){
      printf("Pilha esta vazia \n");
   }
   else{
      printf("Pilha nao esta vazia \n");
   }
}

void Libera_Pilha(Pilha *p){                    //Libera o espaco na memoria alocado para pilha
   while (p->topo != NULL){
      pop(p);
   }
   free(p);
   
}

int Verifica_balanciamento(char dados[], int size){
   Pilha *Pilha_dados = (Pilha*) malloc(sizeof(Pilha));
   create_Pilha(Pilha_dados);
   char Verifica_elemento;
   if(Pilha_dados == NULL){
      printf("Erro na alocacao \n");
      exit(0);
   } else {
      for(int i = 0; i < size; i++){
         if(dados[i] == '{' || dados[i] == '(' || dados[i] == '['){
            push(dados[i], Pilha_dados);
         } else if (dados[i] == '}' || dados[i] == ')' || dados[i] == ']'){
            Verifica_elemento = pop(Pilha_dados);
            if(Verifica_elemento == '(' && dados[i] == ')'){
               continue;
            }else if(Verifica_elemento == '{' && dados[i] == '}'){
               continue;
            }else if(Verifica_elemento == '[' && dados[i] == ']'){
               continue;
            }else{
               printf("Nao balanceado.\n");
               return 0;
            }
         }
      }
      printf("Balanceado.\n");
      return 1;
   }
}

int main(void){
   Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
   char dados[6] = {'(', '}', '{', '}', ')', ')'};
   
   if(p1 == NULL){
      printf("Erro na alocacao da pilha \n");
      exit(0);
   } else {
      create_Pilha(p1);
      push(45, p1);
      push(12, p1);
      Verifica_Pilha(p1);
      pop(p1);
      pop(p1);
      Verifica_Pilha(p1);
      push(45, p1);
      push(12, p1);
      Verifica_Pilha(p1);
      Print_Pilha(p1);
      Libera_Pilha(p1);
      Verifica_Pilha(p1);

      Verifica_balanciamento(dados, 6);
   }

   return 0;
}