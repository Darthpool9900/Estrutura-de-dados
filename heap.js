// Função para imprimir um array
function printArray(arr) {
    console.log(arr.join(' '));
}

// Função para fazer o heapify de uma sub-árvore enraizada no índice 'root'
function heapify(arr, n, root) {
    let maior = root;
    let esq = 2 * root + 1;
    let dir = 2 * root + 2;

    if (esq < n && arr[esq] > arr[maior])
        maior = esq;

    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    if (maior !== root) {
        [arr[root], arr[maior]] = [arr[maior], arr[root]];
        heapify(arr, n, maior);
    }
}

// Função para realizar o heap sort
function heapSort(arr) {
    const n = arr.length;

    // Construir o heap (rearranjar o array)
    for (let i = Math.floor(n / 2) - 1; i >= 0; --i)
        heapify(arr, n, i);

    // Extrair elementos um por um do heap
    for (let i = n - 1; i >= 0; --i) {
        [arr[0], arr[i]] = [arr[i], arr[0]];
        heapify(arr, i, 0);
    }
}

// Exemplo de uso
let arr = [12, 11, 13, 5, 6, 7];
console.log("Array antes da ordenação:");
printArray(arr);

heapSort(arr);

console.log("\nArray depois da ordenação:");
printArray(arr);
