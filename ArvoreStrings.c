//P08270821 - Prática 09/ Árvores de busca binária de strings
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno: Rafael Zachesky de Oliveira RA: 21010026

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    char palavra[100];
    int contador;
    struct no *esq;
    struct no *dir;
};
struct no *raiz = NULL;

void insereArvore(char *valor){

    struct no *atual;
    struct no *anterior;
    struct no *novo;
    novo = (struct no*)calloc(1,sizeof(struct no));
    strcpy(novo->palavra, valor);
    novo->esq = NULL;
    novo->dir = NULL;
    novo->contador = 1;

    if(raiz == NULL){
        raiz = novo;
        printf("Elemento inserido\n");
        return;
    }

    atual = raiz;
    anterior = NULL;
    while(atual != NULL){
        anterior = atual;
        if(strcmp(novo->palavra, atual->palavra) == 0){
            printf("Elemento repitido\n");
            atual->contador++;
            free(novo);
            return;
        }
        if(strcmp(novo->palavra, atual->palavra) < 0){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }

    if(strcmp(novo->palavra, anterior->palavra) < 0){
        anterior->esq = novo;
    }else{
        anterior->dir = novo;
    }

    printf("Elemento inserido\n");
}

void emOrdem(struct no *atual){

    if(atual != NULL){
        emOrdem(atual->esq);
        printf("%s - quantidade: %d\n", atual->palavra, atual->contador);
        emOrdem(atual->dir);
    }
}

int main(){

    char palavra[100];
    FILE *arqTexto;
    arqTexto = fopen("texto.txt", "r");

    if(arqTexto == NULL){
        printf("Arquivo nao encontrado\n");
        return 0;
    }

    while(!feof(arqTexto)){
        if(fscanf(arqTexto, "%s", palavra) != EOF)
            insereArvore(palavra);
    }

    printf("\n\n");

    emOrdem(raiz);

    fclose(arqTexto);

    return 0;
}