#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H

// Estrutura do no da lista
typedef struct ListaSimples ListaSimples;
typedef struct No No;

// Manipulação da lista
ListaSimples* criar_lista();
void preencher_lista(ListaSimples *lista, int n);
void destruir_lista(ListaSimples *lista);

// Busca
No *buscar(ListaSimples *lista, int dado);
void imprimir_lista(ListaSimples *lista);

// Inserção
No *inserir_inicio(ListaSimples *lista, int dado);
No *inserir_fim(ListaSimples *lista, int dado);
No *inserir_posicao(ListaSimples *lista, int dado, int posicao);

// Remoção
int remover_inicio(ListaSimples *lista);
int remover_fim(ListaSimples *lista);
int remover_posicao(ListaSimples *lista, int posicao);

#endif /* LISTASIMPLES_H */
