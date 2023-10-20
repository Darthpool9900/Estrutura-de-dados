#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Função para imprimir um array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Função para fazer o heapify de uma sub-árvore enraizada no índice 'root'
void heapify(int arr[], int n, int root) {
    int maior = root;
    int esq = 2 * root + 1;
    int dir = 2 * root + 2;

    if (esq < n && arr[esq] > arr[maior])
        maior = esq;

    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    if (maior != root) {
        swap(arr[root], arr[maior]);
        heapify(arr, n, maior);
    }
}

// Função para realizar o heap sort
void heapSort(int arr[], int n) {
    // Construir o heap (rearranjar o array)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Extrair elementos um por um do heap
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios

    const int tamanho = 100;
    int numeros[tamanho];

    // Inserir 100 números aleatórios
    for (int i = 0; i < tamanho; ++i) {
        numeros[i] = rand() % 1000; // Gera números aleatórios entre 0 e 999
    }

    // Imprimir array antes da ordenação
    cout << "Array antes da ordenacao:\n";
    printArray(numeros, tamanho);

    // Aplicar o Heap Sort
    heapSort(numeros, tamanho);

    // Imprimir array após a ordenação
    cout << "\nArray depois da ordenacao:\n";
    printArray(numeros, tamanho);

    return 0;
}
