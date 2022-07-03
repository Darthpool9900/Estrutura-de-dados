//P02030622 - Prática 02 Pilhaa
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Rafael Zachesky de Oliveira RA: 21010026
#include<stdio.h>
#define N 10

int topo = -1;
int pilha[N];

int num;

//Adicionionar coisas na pilha
void push(int num){
    //Verifica se a pilha está cheia
    if(topo == N-1){
        printf("A pilha esta cheia por favor remova algo");
        return;
    }else{
        topo = topo+1;
        pilha[topo] = num;
        printf("Valor inserido %d\n", num);
    }
}

//Remover
void pop(int num){
    int aux;
    if(topo == -1){
        printf("A pilha está vazia");
        return;
    }else{
        aux = pilha[topo];
        topo--;
        printf("Item removido:%d\n", aux);
    }
}


void topoPilha(int num){
    if(topo == -1){
        printf("A pilha está vazia");
        return;
    }else{
        printf("Topo:%d\n", num);
    }
}

void imprime(int num){
    int i;
    if(topo == -1){
        printf("A pilha está vazia");
        return;
    }else{
        for(i = topo;i>0;i--){
            printf("item:%d\n",pilha[i]);
    }
    }
}

int main(){
    int num,i,cont;
    char resp;
    for(i = 0;i<N;i++){
        scanf("%d",&num);
        push(num);
        topoPilha(num);
    }
    imprime(num);
    printf("Aperte S enquanto quiser remover um item:\n");
    do{
        scanf("%c",&resp);
        if(resp=='S'){
            pop(num);
        }else{
            cont=1;
        }
    }while(cont==1);
}