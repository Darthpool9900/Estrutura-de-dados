#include<stdio.h>
#define TAM 5

int frente=0,fundo = 0, cont = 0,fila[TAM],i,excluido;

void InsertFila(int valor){
   cont++;
   if(cont<=TAM){
    fila[fundo] = valor;
    if(fundo == TAM-1){
        fundo = 0;
    }
     else{
        printf("inserido:%d\n",fila[fundo]);
            fundo++;
        }
     }
}

void removeFila(){
    cont--;
    if(frente==TAM-1){
            printf("\nRemovido n:%d\n",fila[frente]);
            frente=0;
    }else{
        printf("\nRemovido n:%d\n",fila[frente]);
        frente++;
    }
    }

void primeiro(){
    if(cont==0){
        printf("\nFila vazia");
    }
        printf("primero lugar e:%d\n",fila[frente]);
}

void listar(){
    int i, j = 0;
    if(cont==0){
        printf("\nFila vazia");
    }
    for(i = frente; j < cont; i++){
        if(i == TAM){
            i = 0;
        }
        if(cont<=TAM){
            printf("\nNumero : %d" ,fila[i]);
        j++;
        }
    }
}

void encheFila(){
    int i;
    for(i = 0; i < TAM; i++){
        fila[i] = i + 1;
    }
    cont = TAM;
    fundo = TAM;
    frente = 0;
    printf("cheio\n");
}


int main(){
    int valor,i,resp_esc;
    char resp = 'S';
    printf("-------------------------\n");
    printf("|      1-Inserir        |\n");
    printf("|      2-Remover        |\n");
    printf("|      3-Listar         |\n");
    printf("|  4-Listar primeiro    |\n");
    printf("-------------------------\n");

    do{
        scanf("%d",&resp_esc);
        if(resp_esc==1){
            for(i = 0;i<TAM;i++){
                    scanf("%d",&valor);
                    if(cont==TAM){
                        printf("\nCheio\n");
                    }else{
                        InsertFila(valor);
                    }
            }
            continue;
        }else if(resp_esc==2){
            removeFila();
            continue;
        }else if(resp_esc==3){
            if(cont!=0){
            listar();
            }
            continue;
        }else if(resp_esc==5){
            encheFila();
            continue;
        }
        else{
            primeiro();
            continue;
        }
        primeiro("Deseja continuar?...");
        scanf("%c",&resp);
        if(resp=='N'){
            return 0;
        }
    }while(resp=='S');
    /*for(i=0;i<TAM;i++){
    scanf("%d",&valor);
        InsertFila(valor);
    }
    primeiro();
    listar();
    removeFila();*/
 return 0;
}