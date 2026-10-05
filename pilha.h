#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha {
    char livro[100];
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

void inicializarPilha(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
void empilharLivro(Pilha *pilha, char livro[]);
void consultarPilha(Pilha *pilha);
void desempilharLivro(Pilha *pilha);
void mostrarPilha(Pilha *pilha);
void liberarPilha(Pilha *pilha);

#endif