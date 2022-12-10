#include <stdio.h>
#include <stdlib.h>
 
// Define o tamanho do caractere
#define CHAR_SIZE 26
 
// Estrutura de dados para armazenar um nó Trie
struct Trie
{
    int isLeaf;             // 1 quando o nó é um nó folha
    struct Trie* character[CHAR_SIZE];
};
 
// Função que retorna um novo nó Trie
struct Trie* getNewTrieNode()
{
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf = 0;
 
    for (int i = 0; i < CHAR_SIZE; i++) {
        node->character[i] = NULL;
    }
 
    return node;
}
 
// Função iterativa para inserir uma string em um Trie
void insert(struct Trie *head, char* str)
{
    // inicia do nó raiz
    struct Trie* curr = head;
    while (*str)
    {
        // cria um novo nó se o caminho não existir
        if (curr->character[*str - 'a'] == NULL) {
            curr->character[*str - 'a'] = getNewTrieNode();
        }
 
        // vai para o próximo nó
        curr = curr->character[*str - 'a'];
 
        // move para o próximo caractere
        str++;
    }
 
    // marca o nodo atual como uma folha
    curr->isLeaf = 1;
}
 
// Função iterativa para pesquisar uma string em um Trie. Ele retorna 1
// se a string for encontrada no Trie; caso contrário, retorna 0.
int search(struct Trie* head, char* str)
{
    // retorna 0 se Trie estiver vazio
    if (head == NULL) {
        return 0;
    }
 
    struct Trie* curr = head;
    while (*str)
    {
        // vai para o próximo nó
        curr = curr->character[*str - 'a'];
 
        // se a string for inválida (alcançou o final de um caminho no Trie)
        if (curr == NULL) {
            return 0;
        }
 
        // move para o próximo caractere
        str++;
    }
 
    // retorna 1 se o nodo atual for uma folha e o
    // fim da string é atingido
    return curr->isLeaf;
}
 
// Retorna 1 se um determinado nó Trie tiver filhos
int hasChildren(struct Trie* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (curr->character[i]) {
            return 1;       // filho encontrado
        }
    }
 
    return 0;
}
 
// Função recursivo para deletar uma string de um Trie
int deletion(struct Trie **curr, char* str)
{

    if (*curr == NULL) {
        return 0;
    }
    if (*str)
    {
        if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
            deletion(&((*curr)->character[*str - 'a']), str + 1) &&
            (*curr)->isLeaf == 0)
        {
            if (!hasChildren(*curr))
            {
                free(*curr);
                (*curr) = NULL;
                return 1;
            }
            else {
                return 0;
            }
        }
    }
 
    // se o final da string for atingido
    if (*str == '\0' && (*curr)->isLeaf)
    {
        // se o nodo atual for um nodo folha e não tiver filhos
        if (!hasChildren(*curr))
        {
            free(*curr);    //deleta o nó atual
            (*curr) = NULL;
            return 1;       // exclui os nós pais não-folha
        }
 
        // se o nodo atual for um nodo folha e tiver filhos
        else {
            // marca o nó atual como um nó não folha (DON'T DELETE IT)
            (*curr)->isLeaf = 0;
            return 0;       // não exclui seus nós pais
        }
    }
 
    return 0;
}
 
// Implementação de Trie em C – Inserção, Busca e Exclusão
int main()
{
    struct Trie* head = getNewTrieNode();
 
    insert(head, "hello");
    printf("%d ", search(head, "hello"));       // imprime 1
 
    insert(head, "helloworld");
    printf("%d ", search(head, "helloworld"));  // imprime 1
 
    printf("%d ", search(head, "helll"));       // imprime 0 (Não presente)
 
    insert(head, "hell");
    printf("%d ", search(head, "hell"));        // imprime 1
 
    insert(head, "h");
    printf("%d \n", search(head, "h"));         // imprime 1 + nova linha
 
    deletion(&head, "hello");
    printf("%d ", search(head, "hello"));       // imprime 0 (hello deleted)
    printf("%d ", search(head, "helloworld"));  // imprime 1
    printf("%d \n", search(head, "hell"));      // imprime 1 + nova linha
 
    deletion(&head, "h");
    printf("%d ", search(head, "h"));           // imprime 0 (h deletado)
    printf("%d ", search(head, "hell"));        // imprime 1
    printf("%d\n", search(head, "helloworld")); // imprime 1 + nova linha
 
    deletion(&head, "helloworld");
    printf("%d ", search(head, "helloworld"));  // imprime 0
    printf("%d ", search(head, "hell"));        // imprime 1
 
    deletion(&head, "hell");
    printf("%d\n", search(head, "hell"));       // imprime 0 + nova linha
 
    if (head == NULL) {
        printf("Trie empty!!\n");               // Trie está vazio agora
    }
 
    printf("%d ", search(head, "hell"));        // imprime 0
 
    return 0;
}