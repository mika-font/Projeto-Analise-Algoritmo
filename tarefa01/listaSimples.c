#include "listaSimples.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para o elemento
typedef struct No { 
  int dado;
  No *proximo;
} No;

// Estrutura para a lista
typedef struct ListaSimples { 
  No *primeiro;
  No *ultimo;
} ListaSimples;

ListaSimples *criar_lista() {
  ListaSimples *lista = (ListaSimples *) malloc(sizeof(ListaSimples));
  if (lista == NULL) {
    return NULL;
  }
  lista->primeiro = NULL;
  lista->ultimo = NULL;
  return lista;
}

No *inserir_inicio(ListaSimples *lista, int dado) {

  No *novo = (No *) malloc(sizeof(No));
  if (novo == NULL) {
    return NULL;
  }

  // Atribuir valor e inicializar ponteiro 'proximo'
  novo->dado = dado;
  novo->proximo = NULL;

  // Inserir novo no no inicio da lista
  if (lista->primeiro == NULL) { // Lista vazia
    lista->primeiro = novo;
    lista->ultimo = novo;
  } else { // Lista não vazia
    novo->proximo = lista->primeiro;
    lista->primeiro = novo;
  }
  return novo; // Retornar o ponteiro para o no inserido
}

No *inserir_fim(ListaSimples *lista, int dado) {

  No *novo = (No *) malloc(sizeof(No));
	if (novo == NULL) {
		return NULL;
	}

	// Atribuir valor e inicializar ponteiro 'proximo'
	novo->dado = dado;
	novo->proximo = NULL;

	// Inserir novo no no fim da lista
	if(lista->primeiro == NULL){
	  lista->primeiro = novo;
		lista->ultimo = novo;
	} else {
	  lista->ultimo->proximo = novo;
		lista->ultimo = novo;
	}
	return novo; // Retornar o ponteiro para o no inserido
}

No *inserir_posicao(ListaSimples *lista, int dado, int posicao){

  No *novo = (No *) malloc(sizeof(No));
	if (novo == NULL) {
		return NULL;
	}

	// Atribuir valor e inicializar ponteiro 'proximo'
	novo->dado = dado;
	novo->proximo = NULL;

  int count = 0;
  if(posicao == 0) {
    return inserir_inicio(lista, dado);
  } else {
    No *aux = lista->primeiro;
    while(aux->proximo != NULL){
      if(count+1 == posicao) {
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        return novo;
      }
      aux = aux->proximo;
      count++;
    }
    if(count+1 == posicao) {
      return inserir_fim(lista, dado);
    }
  }
	return NULL;
}

int remover_inicio(ListaSimples *lista) {
  if (lista->primeiro == NULL) {
    return -1; // Lista vazia
  }

  No *removido = lista->primeiro;
  int valor_removido = removido->dado;
  if (lista->primeiro == lista->ultimo) { // Unico no: lista fica vazia
    lista->primeiro = NULL;
    lista->ultimo = NULL;
  } else { // Varios nos: atualizar ponteiros
    lista->primeiro = lista->primeiro->proximo;
  }
  free(removido);
  return valor_removido;
}

int remover_fim(ListaSimples *lista){
  if (lista->primeiro == NULL) {
		return -1; // Lista vazia
	}

	No *removido = lista->ultimo;
	int valor_removido = removido->dado;
  if (lista->primeiro == lista->ultimo) { // Unico no: lista fica vazia
		lista->primeiro = NULL;
		lista->ultimo = NULL;
	} else {
	  No *aux = lista->primeiro; // Varios nos: atualizar ponteiros
		while(aux->proximo != lista->ultimo){
      aux = aux->proximo;
		}
		lista->ultimo = aux;
		aux->proximo = NULL;
	}
	free(removido);
	return valor_removido;
}

int remover_posicao(ListaSimples *lista, int posicao){
  if (lista == NULL || lista->primeiro == NULL || posicao < 0) {
		return -1; // Lista vazia
	}

  int count = 0;
  if(posicao == 0){
    remover_inicio(lista);
  } else {
    No *aux = lista->primeiro;
    No *anterior = NULL;
    while(aux->proximo != lista->ultimo && count < posicao){
      anterior = aux;
      aux = aux->proximo;
      count++;
      if(count+1 == posicao){
        int valor = aux->dado;
        anterior->proximo = aux->proximo;
        free(aux);
        return valor;
      }
    }
    if(count+1 == posicao){
      remover_fim(lista);
    }
  }
}

void imprimir_lista(ListaSimples *lista) {
  if (lista->primeiro == NULL) {
    printf("Lista vazia!\n");
    return;
  }
  No *atual = lista->primeiro;
  while (atual != NULL) {
    printf("%d ", atual->dado);
    atual = atual->proximo;
  }
  printf("\n");
}

void destruir_lista(ListaSimples *lista) {
  if (lista->primeiro == NULL) {
    return;
  }
  No *atual = lista->primeiro;
  No *anterior;
  while (atual != NULL) {
    anterior = atual;
    atual = atual->proximo;
    free(anterior);
  }
  lista->primeiro = NULL;
  lista->ultimo = NULL;
}

No *buscar(ListaSimples *lista, int dado) {
  No *atual = lista->primeiro;

  while (atual != NULL) {
    if (atual->dado == dado) {
      return atual;
    }
    atual = atual->proximo;
  }

  return NULL; // Valor não encontrado
}

void preencher_lista(ListaSimples *lista, int n) {
  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    inserir_fim(lista, rand() % n); 
  }
}