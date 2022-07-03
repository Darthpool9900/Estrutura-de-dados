


#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

struct dados{
    int dado;
    struct dados *prox;
};

struct dados *inicio = NULL;
struct dados *fim = NULL;


void inserir( int valor){//Insere valor dentro da fila
    struct dados *aux;
    aux = (struct no *)malloc(sizeof(struct dados));
    aux -> dado = valor;
    aux -> prox = NULL;
    if(fim == NULL){//Verifica se o final está vazio
        inicio = aux;
        fim = aux; 
    }else{
        fim->prox = aux;
        fim = aux;
    }
    printf("\nInserido:%d",aux -> dado);
}

void remover(){//Remove número da fila
    struct dados *aux;
    if(inicio == NULL){
        printf("\n==================================================");
        printf("\n||                FILA VAZIA                    ||");
        printf("\n==================================================");
    }else if(inicio==fim){
        printf("\nRemovido:%d",fim->dado);
        free(inicio);
        fim== NULL;
    }else{
        aux = inicio;
        inicio = inicio->prox;
        free(aux);
        printf("\nRemovido:%d",aux->dado);
    }
}

void imprimiTopo(){//Imprimi o topo da pilha;
     if(inicio == NULL){
        printf("\n==================================================");
        printf("\n||                FILA VAZIA                    ||");
        printf("\n==================================================");
    }else{
        printf("\n==============================");
        printf("\n||             Frente:%d     ||",inicio-> dado);
        printf("\n==============================");
    }
    return;
}

void Ver_Vazio(){//Verific se a fila está vazia
    if (inicio==NULL)
    {
        printf("\n==================================================");
        printf("\n||                FILA VAZIA                    ||");
        printf("\n==================================================");
    }else{
        printf("\n==================================================");
        printf("\n||                CONTÉM ALGO                   ||");
        printf("\n==================================================");
    }
    return;
}

void PrintALL(struct dados *f_fila){
    struct dados *aux;//imprime a fila inteira
    if (inicio==NULL)
    {
        printf("\n==================================================");
        printf("\n||                FILA VAZIA                    ||");
        printf("\n==================================================");
    }else{
        aux = f_fila;
        while(aux!= NULL){
            printf("\n==================================================");
            printf("\n||                Número:%d                     ||",aux -> dado);
            printf("\n==================================================");
            aux = aux -> prox;
        }
    }
    return;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int resp = 0,resp_fun,insert;
    do{
            printf("\n==================================================");
            printf("\n||                 1-Inserir                    ||");
            printf("\n||                 2-Remover                    ||");
            printf("\n||               3-Mostrar Frente               ||");
            printf("\n||              4-Listar todos                  ||");
            printf("\n||          5-Verifica se está vazia            ||");
            printf("\n||                  6-Sair                      ||");
            printf("\n==================================================\n");
            scanf("%d",&resp_fun);

            if(resp_fun ==1){
                    printf("\n==================================================");
                    printf("\n||                Digite um numero              ||");
                    printf("\n==================================================\n");
                scanf("%d",&insert);
                inserir(insert);
            }else if(resp_fun ==2){
                remover();
            }else if(resp_fun ==3){
                imprimiTopo();
            }else if(resp_fun ==4){
                PrintALL(inicio);
            }else if(resp_fun ==5){
                Ver_Vazio();
            }else if(resp_fun ==6){
                return 0;
            }

    }while(resp == 0);
}