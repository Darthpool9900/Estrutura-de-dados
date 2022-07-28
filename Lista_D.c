//Alunos:Rafael Zachesky de Oliveira, Vitoria Passos Ruppel,Adcleisson Scheifer
//RA:21010026,20016726,21002826
//Estrutura de Dados I - Prof. Albino Szesz Jr.


#include <stdio.h>
#include <stdlib.h>
struct no{//Cria estrutura nó
    int dado;
    struct no *prox;
};
struct cabecalho{//Cria o cabeçalho
    int quantidade;
    struct no *inicio;
};
struct cabecalho *lista;//Declar o ponteiro do cabeçalho

void insere (int i){
    struct no *atual = lista -> inicio;//Insere o 1°elemento
    struct no *anterior = lista; //Insere o valor da lista na posição anterior
    struct no *aux;//declaração de auxiliar

    aux = (struct no*) malloc (sizeof(struct no));//Aloca espaço na memória
    aux -> dado = i;//aux aponta para dado e recebe determinado valor

     while (atual != NULL && atual -> dado <= i) {//Verifica se o atual está vazio e se aponta para posição com o elemnto menor ou igual ao valor inserido
        if(aux->dado==atual->dado){//Verifica se possui elemntos iguais
            printf("Numero nao inserido... Voce digitou um numero que ja esta na lista.\n");
            return;
        }
        anterior = atual;//Anterio recebe valor da posiçõa atual
        atual = atual -> prox;//Atualiza a próxima posiçãp
        }
    aux -> prox = atual;//Recebe o valor atual
    anterior ->prox = aux;//Atualiza a próxima posição
    lista->quantidade++;//Incrementa o cabeçalho
    printf("Numero inserido com sucesso!\n");
}

void busca(int i){
     struct no* aux;
     int j=0;

     if(lista->inicio==NULL){//se a lista esta vaiza 
        printf("Lista Vazia\n");
        return;
     }
     aux=lista->inicio;//posiciona aux no inicio da lista

     printf("Valores: ");
     while(aux!= NULL){//enquanto aux for diferente de nulo
          if(i==aux->dado){//se i for igual ao dado no aux
               printf ("O elemento %d esta na posicao %d\n",i,j);
               return;
               }
          aux=aux->prox;//aux vai para o próximo
          j++;//aumenta j 
     }
     printf("O elemento nao existe na lista\n");
}

void remover(int i){
     struct no *atual=lista->inicio, *anterior=lista;

     if(atual==NULL){ //se lista vazia
        printf("Lista Vazia\n");
        return;
     }

     while(atual!=NULL){
           if(atual->dado==i){  //se ele achar o i na lista
              anterior->prox=atual->prox; //anterior recebe atual
              free(atual); //libera atual
              lista->quantidade--; //contador
              printf("Elemento removido com sucesso!\n");
              return;
              }
           else {
               anterior=atual; //anterior recebe atual
               atual=atual->prox; //atua recebe o prox endereço
                }
     }

     printf("Este numero nao existe na lista!\n");
}



void imprime(){
struct no* aux;

     if(lista->inicio==NULL){ //se lista vazia 
        printf("Lista Vazia\n");
        return;
     }
     aux=lista->inicio; //posicionar o aux no inicio
     printf("Numeros de elementos na lista (cabecalho):%d\n\n",lista->quantidade); //contador
     printf("Valores: ");
     while(aux!= NULL){ //enquanto aux diferente de nulo
          printf("%d ", aux->dado); //printa os dados
          aux=aux->prox; //aux aponta para o prox
     }
     printf("\n");
}

int main() {
    lista = (struct cabecalho*) malloc (sizeof(struct cabecalho)); //aloca memoria
    lista -> quantidade=0; //quantidade = 0
    lista -> inicio=NULL; //inicio é vazio
    int i, aux;
    printf("\n\nMenu:\n[1] - Inserir um elemento.\n[2] - Remover um elemento.\n[3] - Buscar\n[4] - Imprimir lista\n[5] - Sair\n\n ");
    while(aux!=5){
    printf(">> ");
    scanf("%d", &aux);

    switch(aux){

           case 1:printf("Elemento a ser inserido: ");
                  scanf("%d",&i);
                  insere(i);
                  break;
           case 2:printf("Elemento a ser removido: ");
                  scanf("%d", &i);
                  remover(i);
                  break;
           case 3:printf("Elemento a ser buscado: ");
                  scanf("%d", &i);
                  busca(i);
                  break;
           case 4:imprime();
                  break;

    }
    }
}
LISTA_COM_CABECALHO.c
Exibindo LISTA_COM_CABECALHO.c…