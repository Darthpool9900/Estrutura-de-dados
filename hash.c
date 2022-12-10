//P0625112022 - Prática 06 Tabela de espalhamento
//Estrutura de Dados II - Prof. Albino Szesz Jr.
//Aluno Rafael Zachesky de Oliveira RA: 21010026


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM 101


int A[TAM];
int cont_tam = 0;
int cont_busca = 0;


int espalhamento(int key){//Faz o primeiro espalhamento
    return(key%TAM);
}

int reespalhamento(int pos){//Reespalha os valores da tabela
    return((pos+1)%TAM);
}

void start(){
    int i;
    for(i = 0; i <TAM;i++){
        A[i] = -1;
    }
}

int insert(int key){
    int pos;
    if(cont_tam == TAM){
        printf("\n============================");
        printf("\n||        Cheio           ||");
        printf("\n============================");
    }

    pos = espalhamento(key);
    if(A[pos] == -1){
        A[pos] = key;
        cont_tam++;
        return;
    }
    while(A[pos] != -1){
        pos = espalhamento(pos);
    }
    A[pos] = key;
    cont_tam++;
}

int search(int key){
    int pos;
    cont_busca = 0;
    pos = espalhamento(key);
    if(A[pos] == -1){
        return;
    }
    if(A[pos] == key){
       printf("\n================================");
    printf("\n||        Número buscado:%d   ||",key);
    printf("\n||       Total de buscas:%d   ||",cont_busca);
    printf("\n================================");
        return pos;
    }

    while(A[pos]!=-1 && cont_busca!=TAM){
        pos = reespalhamento(key);
        if(A[pos] == key){
            printf("\n================================");
            printf("\n||        Número buscado:%d   ||",key);
            printf("\n||       Total de buscas:%d   ||",cont_busca);
            printf("\n================================");
            cont_busca++;
            return pos;
        }
    }
}

void imprime(){
    int i;
    for(i = 0; i <TAM;i++){
            printf("\n=============================================");
            printf("\n||        Númerp:%d na posição:%d          ||", A[i],i );
            printf("\n============================================");
    }
    printf("\n");
}

void random_gem(){
    int i,elem;
    for(i = 0; i <TAM;i++){
        elem = i*2;
        insert(elem);
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i,elem,ans = -1;
    int num;
    while(ans = -1){
    srand(time(NULL));
    
    printf("\n1-Inicia tabela,2-Preencher,3-buscar,4 Imprimir");
    scanf("%d",&ans);
    switch(ans){
                case 0:
                    return 0;
                case 1:
                    start();
                    break;
                case 2:
                    random_gem();
                    break;
                case 3:
                    printf("\nDigite o número a ser procurado");
                    scanf("%d",&num);
                    search(num);
                    break;
                case 4:
                    imprime();
                    break;
    }
    }
}
