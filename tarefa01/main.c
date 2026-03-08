#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include "listaSimples.h"
#include <time.h>

int main() {
  ListaSimples *minhaLista = criar_lista();

  int valor;
  printf("Digite o tamanho da lista: ");
  if (scanf("%d", &valor) != 1 || valor <= 0) {
    printf("Entrada inválida. Por favor, insira um número inteiro positivo.\n");
    destruir_lista(minhaLista);
    return 1;
  }

  preencher_lista(minhaLista, valor);
  printf("Lista preenchida com %d elementos.\n", valor);

  const int repeticoes = 10;
  struct timespec ini, fim;

  clock_gettime(CLOCK_MONOTONIC, &ini);

  for (int i = 0; i < repeticoes; i++) {
    buscar(minhaLista, -1);
  }

  clock_gettime(CLOCK_MONOTONIC, &fim);

  printf("Busca realizada %d vezes.\n", repeticoes);

  double tempoTotal_ms = (fim.tv_sec - ini.tv_sec) * 1000.0 + (fim.tv_nsec - ini.tv_nsec) / 1000000.0;
  double tempoMedio_ms = tempoTotal_ms / repeticoes;

  printf("Tempo total: %.0f ms\n", tempoTotal_ms);
  printf("Tempo médio: %.3f ms\n", tempoMedio_ms);

  destruir_lista(minhaLista);
  printf("Lista destruída.\n");
  return 0;
}
