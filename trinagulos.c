// Problema: Triangulos
// Autor: Jaime Cohen

#include <stdio.h>

#define MAXN 100000

int busca(int p, int *pontos, int n);


int main()
{
  int N, x, i, circ, circ_div_3;
  int p1, p2, p3;
  int num_triangulos = 0; // numero de triangulos equilateros
  int pontos[MAXN];

  // leitura da entrada
  scanf("%d ", &N);
  pontos[0] = 0;
  for (i=0; i<N-1; ++i) {
    scanf("%d ", &x);
    pontos[i+1] = pontos[i] + x;
  }
  scanf("%d ", &x);
  circ = pontos[N-1] + x; // comprimento da circunferencia
  if (circ%3)  {          // circunferencia nao eh multiplo de 3
    printf("0\n");
    return 0;
  }
  // procura e conta os triangulos equilateros
  circ_div_3 = circ/3;
  for (i=0; i<N && pontos[i] < circ_div_3; ++i) {
    p1 = pontos[i];
    p2 = p1 + circ_div_3;
    p3 = p2 + circ_div_3;
    if (busca(p2, pontos, N) && busca(p3, pontos, N))
      num_triangulos++;
  }    
  printf("%d\n", num_triangulos);
  return 0;
}

// Busca Binaria
// Entrada:
//   p      : valor a ser procurado
//   pontos : um vetor ordenado de inteiros
//   n      : o numero de elementos em pontos[]
// Saida: 1 achou, 0 caso contrario
int busca(int p, int *pontos, int n)
{
  int i;
  int m, left, right;

  left = 0; right = n-1;
  while (right >= left) {
    m = (left+right)/2;
    if (p == pontos[m]) // achou
      return 1;
    if (p < pontos[m])
      right = m-1;
    else left = m+1;
  }
  return 0;  // nao achou
}