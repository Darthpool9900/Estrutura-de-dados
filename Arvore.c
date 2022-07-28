#include <stdio.h>
#include <stdlib.h>

struct no{
       int dado;
       struct no *esq,*dir;
};
struct no *raiz = NULL;

void insere(int i){
     struct no *aux, *atual;
     
     aux=(struct no*)malloc (sizeof(struct no));
     aux -> dado = i;
     aux -> esq = NULL;
     aux -> dir = NULL;
     if(raiz == NULL){
        raiz = aux;
        printf ("Elemento inserido com sucesso!\n\n");
        return;
     }
     atual = raiz;
     while(1){
           
           if(aux -> dado >= atual -> dado){ 
              if(atual -> dir == NULL){ 
                 atual -> dir = aux;
                 printf ("Elemento inserido com sucesso!\n\n");
                 return;       
              }
              atual = atual -> dir; 
           }
           else{ 
               if(atual -> esq == NULL){
                  atual -> esq = aux;
                  printf ("Elemento inserido com sucesso!\n\n");
                  return;
               }
               atual = atual -> esq;
           }
     }
}

void em_ordem(struct no *atual){ 
     
     if(atual != NULL){
        em_ordem(atual -> esq);
        printf ("%d ",atual -> dado);
        em_ordem(atual -> dir);
     }
}

void busca(int i){
        while(raiz!= NULL){
            if(raiz->dado==i){
                printf ("\n============================");
                printf("\n||    Valor encontarado:%d ||",raiz->dado);
                printf("\n==============================");
                return;
            }
            else if(i>raiz->dado){
                    raiz = raiz ->dir;
            }else{
                raiz = raiz ->esq;
            }
            }
}



int main(){
    int resp;
    int valor;
    struct no *ref;
     printf("\n================================================");
        printf("\n||                1-Inserir                   ||");
        printf("\n||                2-busca                     ||");
        printf("\n||            3-Imprimir em ordem             ||");
        printf("\n================================================");

        scanf("%d",&resp);
    while(resp<=4){
        printf("\n================================================");
        printf("\n||                1-Inserir                   ||");
        printf("\n||                2-busca                     ||");
        printf("\n||            3-Imprimir em ordem             ||");
        printf("\n||                4-sair                      ||");

        printf("\n================================================");

        scanf("%d",&resp);
        if(resp==1){
            printf("\n================================================");
            printf("\n||                Insira um numero             ||");
            printf("\n================================================\n");

            scanf("%d",&valor);
            insere(valor);

        }else if(resp==2){
            printf("\n================================================");
            printf("\n||                Insira um numero             ||");
            printf("\n================================================\n");

            scanf("%d",&valor);

            busca(valor);
        }else if(resp==3){
            em_ordem(raiz);
        }else if(resp==4){
            return 0;
        }
    }
  
}