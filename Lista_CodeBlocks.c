//P04170622 - Prática 04 LISTA LINEAR
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Jack Bauer RA: 081040526

#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#define TAM 3

int lista[TAM], cont =0;

void inserir(int Valor){//Insere valor dentro da lista
    int aux;

    if(cont==TAM){//Verifica se está vázio
        printf("\nLista cheia");
    }else if(cont<TAM){
        for(aux=0;aux<cont;aux++){
            if(lista[aux]==Valor){
                printf("\nElemento não inserido pois elemento %d já está na lista",lista[aux]);
                return;
            }
        }
        lista[cont] = Valor;
        cont++;
        printf("\nElemento inserido");
    }
}

void remover(int valor){
    int i, marcador;
    for(i = 0; i < cont; i++){
        if(lista[i] == valor){
            marcador = i;
        }
    }
    for(i = marcador; i < cont; i++){
        lista[i] = lista[i + 1];
    }
    cont--;
}

void busca(int valor){//Busca valor
    int aux;
    if(cont==0){//Verifica se já existe uma lista
        printf("\nLista vazia");
        return;
    }
    for(aux=0;aux<cont;aux++){
        if(lista[aux]==valor){//Verifica se achou valor
            printf("\nEncontrado:%d",lista[aux],aux);
            return;
        }else{
            printf("\nNenhum elemento encontrado");
        }
    }
}

void imprime(){
    int aux;
    if(cont==0){
        printf("\nLista vazia");
    }
    for(aux=0;aux<cont;aux++){
        printf("\nNúmero:%d",lista[aux]);
    }
}

main(){
   setlocale(LC_ALL, "Portuguese");
    int a, case_resp,loop;
    do{
    printf("-------------------------\n");
    printf("-          1-Inserir    -\n");
    printf("-          2-Remover    -\n");
    printf("-          3-Buscar     -\n");
    printf("-          4-Listar     -\n");
    printf("-          5-sair       -\n");
    printf("-------------------------\n");
    scanf("%d",&case_resp);

        if(case_resp==1){
            printf("Digite um valor:");
            scanf("%d",&a);
            inserir(a);
        }else if(case_resp==2){
            printf("Digite um valor:");
            scanf("%d",&a);
            remover(a);
        }else if(case_resp==3){
            printf("Digite um valor:");
            scanf("%d",&a);
            busca(a);
        }else if(case_resp==4){
            imprime();
        }else if(case_resp==5){
            return 0;
        }

        printf("\nDeseja continuar:");
        scanf("%d",&loop);

    }while(loop==1);

    return 0;
}
