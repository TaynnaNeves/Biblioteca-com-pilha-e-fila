#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila *fila) {
    return fila->inicio == NULL;
}

void entrarFila(Fila *fila, char nome[]) {

    NoFila *novo = malloc(sizeof(NoFila));

    if (novo == NULL) {
        printf("Erro: infelizmente nao foi possivel alocar memoria.\n");
        return;
    }

    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    printf("%s entrou na fila.\n", nome);
}

void consultarFila(Fila *fila) {

    if (filaVazia(fila)) {
        printf("Deu sorte, A fila esta vazia.\n");
        return;
    }

    printf("Proxima pessoa por favor: %s\n", fila->inicio->nome);
}

void sairFila(Fila *fila) {

    if (filaVazia(fila)) {
        printf("A fila esta vazia. Infelizmente Ninguem pode ser atendido.\n");
        return;
    }

    NoFila *removido = fila->inicio;

    printf("%s foi atendido e saiu da fila.\n", removido->nome);

    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);
}

void mostrarFila(Fila *fila) {

    if (filaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    NoFila *atual = fila->inicio;

    printf("\n--- FILA DE ATENDIMENTO NA BIBLIOTECA---\n");

    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->proximo;
    }
}

void liberarFila(Fila *fila) {

    NoFila *atual = fila->inicio;

    while (atual != NULL) {

        NoFila *removido = atual;
        atual = atual->proximo;

        free(removido);
    }

    fila->inicio = NULL;
    fila->fim = NULL;
}