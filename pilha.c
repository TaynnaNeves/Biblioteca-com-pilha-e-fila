#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

void empilharLivro(Pilha *pilha, char livro[]) {

    NoPilha *novo = malloc(sizeof(NoPilha));

    if (novo == NULL) {
        printf("Erro: infelizmente nao foi possivel alocar memoria.\n");
        return;
    }

    strcpy(novo->livro, livro);

    novo->proximo = pilha->topo;

    pilha->topo = novo;

    printf("Livro \"%s\" foi colocado no topo da pilha.\n", livro);
}

void consultarPilha(Pilha *pilha) {

    if (pilhaVazia(pilha)) {
        printf("A pilha esta vazia.\n");
        return;
    }

    printf("Livro no topo: %s\n", pilha->topo->livro);
}

void desempilharLivro(Pilha *pilha) {

    if (pilhaVazia(pilha)) {
        printf("A pilha esta vazia. Nao ha livro para retirar.\n");
        return;
    }

    NoPilha *removido = pilha->topo;

    printf("Livro \"%s\" foi retirado da pilha.\n",
           removido->livro);

    pilha->topo = removido->proximo;

    free(removido);
}

void mostrarPilha(Pilha *pilha) {

    if (pilhaVazia(pilha)) {
        printf("A pilha esta vazia.\n");
        return;
    }

    NoPilha *atual = pilha->topo;

    printf("\n--- PILHA DE LIVROS DA BIBLIOTECA ---\n");

    while (atual != NULL) {
        printf("%s\n", atual->livro);
        atual = atual->proximo;
    }
}

void liberarPilha(Pilha *pilha) {

    NoPilha *atual = pilha->topo;

    while (atual != NULL) {

        NoPilha *removido = atual;
        atual = atual->proximo;

        free(removido);
    }

    pilha->topo = NULL;
}