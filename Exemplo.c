#include<stdio.h>
#include<stdlib.h>
#define TAM 10000

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
}

