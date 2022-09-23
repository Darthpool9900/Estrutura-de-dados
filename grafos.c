//P10050822 - Prática 1/ Grafos
//Estrutura de Dados II - Prof. Albino Szesz Jr.
//Aluno Rafael Zachesky de Oliveira RA: 21010026


#include<stdio.h>
#include<locale.h>
#include<conio.h>
#define TAM 10

//Escopo para variáveis globais
int vertice[TAM];
int matriz_adj[TAM][TAM];
int cont=0;


void Refresh(){//Reinicia os grafos
int i,j= 0;
    int aux_primario,aux_secundario = 0;//Decalaração de variáveis auxiliares para percorrer a matriz
        for(i=0;i<TAM;i++){
            matriz_adj[i][j] = 0;
            j++;
        }
}

void insereVertice(int val){//Insere valores dentro dos grafos
    int i;
    if(cont==TAM){//Verifica se o vetor já está cheio
        printf("\nVetor cheio");
        return;
    }
    for(i=0;i<TAM;i++){
        if(vertice[i]==val){//Verifica se já existe um valor igual dentro do vetor
            printf("\nElemento repitido");
            return;
        }
    }
    vertice[cont]=val;
    printf("\nValor inserido:%d",vertice[cont]);
    cont++;
}

void inserirAresta(int val_init,int val_destiny){//Insere dois vertices sendo o primeiro o valor inicial e o segundo o valor de destino
    int i,aux_move=-1,aux_ret=-1;//Declaração de variáveis auxiliares
    for( i=0;i<TAM;i++){
        if(vertice[i]==val_init){
            aux_move=i;
        }
        if(vertice[i]==val_destiny){
            aux_ret=i;
        }
    }
    if(aux_move==-1||aux_ret==-1){//Verifica se os vertices existem
        printf("Vetor não encontrado");
    }
    matriz_adj[aux_move][aux_ret]=1;
}

void imprimeGrafo(){//Imprime o grafo completo
    int i,j;
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
        if(matriz_adj[i][j]==1){
            printf("\nInicio:%d,Fim:%d",vertice[i],vertice[j]);
        }
        }
    }
}

void removeAresta(int val_init,int val_destiny){
    int i,aux_move=-1,aux_ret=-1;//Declaração de variáveis auxiliares
    if(matriz_adj[aux_move][aux_ret]==NULL){
        printf("\nVetores ou Grafo inexistente");
        return;
    }
    for( i=0;i<TAM;i++){
        if(vertice[i]==val_init){
            aux_move=i;
        }
        if(vertice[i]==val_destiny){
            aux_ret=i;
        }
    }
    if(aux_move==-1||aux_ret==-1){//Verifica se os vertices existem
        printf("Vetor não encontrado");
    }
    matriz_adj[aux_move][aux_ret]=-1;
    printf("\nRemovido");
}
void verificaAresta(int val_init,int val_destiny){
    
    int aux1 = -1, aux2 = -1,i;

    for(i = 0; i < cont; i++){
        if(val_init == vertice[i])
            aux1 = i;
        if(val_destiny == vertice[i])
            aux2 = i;
    }

    if(aux1 == -1 || aux2 == -1){
        printf("Vertice nao encontrado!\n");
        return;
    }

    if(matriz_adj[aux1][aux2] == 1)
        printf("Ha uma aresta entre os vertices %d e %d\n", vertice[aux1], vertice[aux2]);
    else
        printf("Nao ha uma aresta entre os vertices %d e %d\n", vertice[aux1], vertice[aux2]);
}

int main(){
    int resp = 0,leitor,i,valor,aux_valor;
    setlocale(LC_ALL,"Portguese");
    while(resp==0){
        printf("\n================================================");
        printf("\n||              1-Inserir vertice             ||");
        printf("\n||              2-Criar aresta                ||");
        printf("\n||              3-Remover aresta              ||");
        printf("\n||              4-Imprimir                    ||");
        printf("\n||         5-Verifica se existe aresta        ||");
        printf("\n================================================");
        scanf("\n%d",&leitor);
        if(leitor==1){
            Refresh();
            for(i=0;i<TAM;i++){
                printf("\nDigite um numero:");
                scanf("%d",&valor);
                insereVertice(valor);
            }
        }else if(leitor==2){
            printf("\nDigite dois numeros:");
                scanf("%d",&valor);
                scanf("%d",&aux_valor);
                inserirAresta(valor,aux_valor);
        }else if(leitor==3){
            printf("\nDigite dois numeros:");
                scanf("%d",&valor);
                scanf("%d",&aux_valor);
                removeAresta(valor,aux_valor);
        }else if(leitor==4){
            imprimeGrafo();
        }else if(leitor==5){
            printf("\nDigite dois numeros:");
                scanf("%d",&valor);
                scanf("%d",&aux_valor);
                verificaAresta(valor,aux_valor);
        }else{
            return 0;
        }
    }
}
