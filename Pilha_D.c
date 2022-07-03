//P02030622 - Prática 02 Pilhaa
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Rafael Zachesky de Oliveira RA: 21010026
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <windows.h>


struct dados{
    int dado;
    struct dados *prox;
};

 struct dados *pilha = NULL;

//Adicionionar coisas na pilha
void push(int valor){
    struct dados *aux;
        aux=(struct dados*)malloc(sizeof(struct dados));
        aux -> dado = valor;
        aux -> prox = pilha;
        pilha = aux;
        printf("\nAdicionado número:%d",aux->dado);
}

//Remover
void pop(){
    struct dados *aux;
    int i;
    if(aux==NULL){
        printf("\n==================================================");
        printf("\n||                PILHA VAZIA                   ||");
        printf("\n==================================================\n");
    }else{
        i = pilha->dado;
        aux = pilha;
        pilha = pilha -> prox;
        printf("\nEliminado:%d",i);
        free(aux);
    }
}


void topoPilha(){
        printf("Topo:%d\n",pilha -> dado);
}

void imprime(struct dados *tpilha){
    struct dados *prot;
    prot = tpilha;
    while(prot != NULL){
        printf("\n==================================================");
        printf("\n||                Número:%d                     ||",prot -> dado);
        printf("\n==================================================");
        prot = prot -> prox;
        
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
            printf("\n||               3-Mostrar topo                 ||");
            printf("\n||              4-Listar todos                  ||");
            printf("\n||                  5-Sair                      ||");
            printf("\n==================================================\n");
            scanf("%d",&resp_fun);

            if(resp_fun ==1){
                    printf("\n==================================================");
                    printf("\n||                Digite um numero              ||");
                    printf("\n==================================================\n");
                scanf("%d",&insert);
                push(insert);
            }else if(resp_fun ==2){
                pop();
            }else if(resp_fun ==3){
                topoPilha();
            }else if(resp_fun ==4){
                imprime(pilha);
            }else if(resp_fun ==5){
                return 0;
            }

    }while(resp == 0);

}
