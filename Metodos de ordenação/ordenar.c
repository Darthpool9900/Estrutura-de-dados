//P10050822 - Prática 10/ Algoritmos de Ordenação
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Rafael Zachesky de Oliveira RA: 21010026
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 1000

int lista[tam * 100], tamanho;

void bubbleSort(){//Função para ordenação através bubble sort

    int limite = 1, cont, aux;//Declaração de variaveis
    int ordenada = 0;
    unsigned long int comps = 0, trocas = 0;
    clock_t inicial, final;
    double tempo;

    inicial = (double) clock();//Declaração do relógio
    while(ordenada == 0 && limite < tamanho){//Verifica se há algo existente
        ordenada = 1;
        for(cont = 0; cont <= tamanho - limite - 1; cont++){//Fluxo de repetição para odernar
            if(lista[cont] > lista[cont + 1]){//Verifica o final
                aux = lista[cont];
                lista[cont] = lista[cont + 1];
                lista[cont + 1] = aux;
                trocas++;
                ordenada = 0;
            }
            comps++;
        }
        limite++;//Avança limite
    }
    final = (double) clock();

    tempo = final - inicial;//
    printf("===================================\n");
    printf("||        Lista ordenada         ||\n");
    printf("||      Tempo de execucao: %f    ||\n", tempo);
    printf("||      Comparacoes: %d          ||\n", comps);
    printf("||          Trocas: %d           ||\n", trocas);
    printf("===================================\n");

    system("pause");
    system("cls");
}

void selectionSort(){//Função para  através de selection sort

    int cont1, cont2, atual, aux;//Declaração de variavéis
    unsigned long int comps = 0, trocas = 0;
    clock_t inicial, final;
    double tempo;

    inicial = (double) clock();//Declaração de relógio
    for(cont1 = 0; cont1 <= tamanho - 2; cont1++){//Inicio do fluxo para organizar 
        atual = cont1;
        for(cont2 = cont1 + 1; cont2 <= tamanho - 1; cont2++){//Incrementa contador 1
            if(lista[atual] > lista[cont2])//Verifica se o valor do vetor atual é maior que é vetor da frente
                atual = cont2;
            comps++;
        }
        aux = lista[cont1];
        lista[cont1] = lista[atual];
        lista[atual] = aux;
        trocas++;
    }
    final = (double) clock();

    tempo = final - inicial;//Cálculo do tempo
    printf("===================================\n");
    printf("||         Lista ordenada         ||\n");
    printf("||       Tempo de execucao: %f    ||\n", tempo);
    printf("||          Comparacoes: %d       ||\n", comps);
    printf("||            Trocas: %d          ||\n", trocas);
    printf("===================================\n");

    system("pause");
    system("cls");
}

void insertionSort(){//Função de ordenação através de insertion sort

    int cont1, cont2, valor, aux;
    int ordenada;
    unsigned long int comps = 0, trocas = 0;
    clock_t inicial, final;
    double tempo;

    inicial = (double) clock();//Declaração de relógio 
    for(cont1 = 1; cont1 <= tamanho - 1; cont1++){//Inicia ordenção
        valor = lista[cont1];
        cont2 = cont1 - 1;
        ordenada = 0;
        while(cont2 >= 0 && ordenada == 0){//Verfica se contador 2 é maior que 0 e se ordenada é 0
            if(lista[cont2] > valor){//Verifica se o valor do vetor é maior que o valor inserido
                aux = lista[cont2];
                lista[cont2] = lista[cont2 + 1];
                lista[cont2 + 1] = aux;
                cont2--;
                trocas++;
            }else
                ordenada = 1;
            comps++;
        }
    }
    final = (double) clock();

    tempo = final - inicial;//Calcula o tempo

    printf("===================================\n");
    printf("||         Lista ordenada         ||\n");
    printf("||       Tempo de execucao: %f    ||\n", tempo);
    printf("||          Comparacoes: %d       ||\n", comps);
    printf("||            Trocas: %d          ||\n\n", trocas);
    printf("===================================\n");

    system("pause");
    system("cls");
}

unsigned long int compsQ = 0, trocasQ = 0;

int particao(int esq, int dir){//Organizar por partição

    int aux, pivo, cont1, cont2;

    pivo = lista[esq];
    cont1 = esq - 1;
    cont2 = dir + 1;
    while(1){//Verifica se é verdadeiro

        do
            cont1++;//Incrementa contador 1
        while(lista[cont1] < pivo);

        do
            cont2--;
        while(lista[cont2] > pivo);//Verifica o valor do vetor é maior que o do pivot

        if(cont1 < cont2){//Verifica os contadores
            aux = lista[cont1];
            lista[cont1] = lista[cont2];
            lista[cont2] = aux;
            trocasQ++;
        }else
            return cont2;
        compsQ++;
    }
}

void quickSort(int esq, int dir){//Função que utiliza método quicksort

    int meio;

    if(esq < dir){//Verifica se a esquerda é maior que a direita
        meio = particao(esq, dir);
        quickSort(esq, meio);//Recursividade
        quickSort(meio + 1, dir);//Recursividade
    }
}

void ordenaLista(){//Menu para escolha de opções de tamanho e ordem de ordenação

    int opcTam, opcOrd, opcAlg, cont, valor;
    int esc = 0;

    while(esc == 0){
        printf("===============================\n");
        printf("||  Qual o tamanho da lista? ||\n");
        printf("||          1 - 1000         ||\n");
        printf("||          2 - 10000        ||\n");
        printf("||          3 - 100000       ||\n");
        printf("===============================\n");
        printf("Opcao escolhida: ");
        scanf("%d", &opcTam);

        printf("\n");

        switch(opcTam){
            case 1:
                esc = 1;
                tamanho = tam;
                printf("Tamanho da lista: %d\n\n", tam);
                break;
            case 2:
                esc = 1;
                tamanho = tam * 10;
                printf("Tamanho da lista: %d\n\n", tam * 10);
                break;
            case 3:
                esc = 1;
                tamanho = tam * 100;
                printf("Tamanho da lista: %d\n\n", tam * 100);
                break;
            default:
                printf("Opcao invalida\n\n");
                system("pause");
                system("cls");
                break;
        }
    }

    esc = 0;

    while(esc == 0){//Verifica se a saida é 0
        printf("====================================\n");
        printf("|| Qual o preenchimento da lista? ||\n");
        printf("||       1 - Ordem crescente      ||\n");
        printf("||       2 - Ordem decrescente    ||\n");
        printf("||       3 - Ordem aleatoria      ||\n");
        printf("====================================\n");
        printf("Opcao escolhida: ");
        scanf("%d", &opcOrd);

        printf("\n");

        switch(opcOrd){//Opções de preenchimento
            case 1:
                esc = 1;
                for(cont = 0; cont < tamanho; cont++)
                    lista[cont] = cont;
                printf("Lista preenchida em ordem crescente\n\n");
                break;
            case 2:
                esc = 1;
                valor = tamanho - 1;
                for(cont = 0; cont < tamanho; cont++){
                    lista[cont] = valor;
                    valor--;
                }
                printf("Lista preenchida em ordem decrescente\n\n");
                break;
            case 3:
                esc = 1;
                for(cont = 0; cont < tamanho; cont++)
                    lista[cont] = rand() % tamanho;
                printf("Lista preenchida em ordem aleatoria\n\n");
                break;
            default:
                printf("Opcao invalida\n\n");
                system("pause");
                system("cls");
                break;
        }
    }

    esc = 0;

    while(esc == 0){//Verfica se a sáida é igual a 0
        printf("========================================\n");
        printf("||     Qual o algoritmo de ordenacao? ||\n");
        printf("||            1 - Bubble Sort         ||\n");
        printf("||            2 - Selection Sort      ||\n");
        printf("||            3 - Insertion Sort      ||\n");
        printf("||            4 - Quick Sort          ||\n");
        printf("========================================\n");
        printf("Opcao escolhida: ");
        scanf("%d", &opcAlg);

        printf("\n");

        switch(opcAlg){
        case 1:
            esc = 1;
            printf("Ordenando lista...\n\n");
            bubbleSort();
            break;
        case 2:
            esc = 1;
            printf("Ordenando lista...\n\n");
            selectionSort();
            break;
        case 3:
            esc = 1;
            printf("Ordenando lista...\n\n");
            insertionSort();
            break;
        case 4:
            esc = 1;
            compsQ = 0;
            trocasQ = 0;
            clock_t inicial, final;
            double tempo;
            printf("Ordenando lista...\n\n");
            inicial = (double) clock();
            quickSort(0, tamanho);
            final = (double) clock();
            tempo = final - inicial;
            printf("Lista ordenada\n");
            printf("============================\n");
            printf("||  Tempo de execucao: %f ||\n", tempo);
            printf("||     Comparacoes: %d    ||\n", compsQ);
            printf("||       Trocas: %d       ||\n", trocasQ);
            printf("============================\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Opcao invalida\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
}

int main(){

    char opcao;

    do{
        setbuf(stdin, 0);

        printf("Quer ordenar uma lista?[S/N]: ");
        scanf("%c", &opcao);

        if(opcao == 's' || opcao == 'S'){//Compara caracteres para continuar o procedimento
            system("cls");
            ordenaLista();
        }else if(opcao == 'n' || opcao == 'N'){//Compara caracteres para continuar o procedimento
            printf("\nSaindo...\n");
            return 0;
        }else{
            printf("\nOpcao invalida\n\n");
            system("pause");
            system("cls");
        }

    }while(opcao != 'n' || opcao != 'N');
}