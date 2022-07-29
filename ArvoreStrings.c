//P02030622 - Prática 02 Pilhaa
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Rafael Zachesky de Oliveira RA: 21010026

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
        char palavra[100];
        int contador;
        struct no *esq,*dir;
};
struct no *raiz = NULL;

void insere(char *texto){//Insere uma palavra dentro da árvore binária
     struct no *anterior, *atual, *novo;
     
     novo=(struct no*)malloc (sizeof(struct no));
     strcpy(novo->palavra,texto);
     novo -> esq = NULL;
     novo -> dir = NULL;
     novo -> contador =1;
     if(raiz == NULL){
        raiz = novo;
                printf("\n================================================");
                printf("\n||            Elemento inserido               ||");
                printf("\n================================================");
        return;
     }
     atual = raiz;
     anterior=NULL;
     while(atual != NULL){
           
           if(strcmp(novo->palavra,atual->palavra)==0){ 
                printf("\n================================================");
                printf("\n||            Elemento repetido               ||");
                printf("\n================================================");
                atual->contador++;
                free(novo);
                return;
           }
           else if(strcmp(novo->palavra,atual->palavra)<0){ 
                    atual = atual -> esq;
               }else{
                    atual = atual -> dir;
               }
           }
        if(strcmp(novo->palavra,anterior->palavra)<0){
            anterior->esq = novo;
        }else{
            anterior->dir = novo;
        }
                printf("\n================================================");
                printf("\n||            Elemento inserido               ||");
                printf("\n================================================");
     }


void em_ordem(struct no *atual){ 
     
     if(atual != NULL){
        em_ordem(atual -> esq);
         printf("\n================================================");
        printf ("\n%s ",atual -> palavra);
        printf("\n================================================");
        em_ordem(atual -> dir);
     }
}


int main(){
    int resp;
    char letras[100];
    FILE *file;
    
     resp=0;
    while(resp<=4){
        if(file==NULL){
                printf("\n================================================");
                printf("\n||               Arquivo inexistente          ||");
                printf("\n================================================\n");
            }
        
        printf("\n================================================");
        printf("\n||                1-Inserir                   ||");
        printf("\n||                2-busca                     ||");
        printf("\n||            3-Imprimir em ordem             ||");
        printf("\n||                4-sair                      ||");

        printf("\n================================================");

        scanf("%d",&resp);
        if(resp==1){
            while(!feof(file)){
                printf("\n================================================");
                printf("\n||                Insira uma palavra          ||");
                printf("\n================================================\n");
                file  = fopen("letras.txt", "w");
                fscanf("%s",letras);
                    insere(letras);
            }
            file = fclose(file);
        }else if(resp==2){
            

           
        }else if(resp==3){
            file  = fopen("letras.txt", "r");
            em_ordem(raiz);
            file = fclose(file);
        }else if(resp==4){
            return 0;
        }
    }
  
}