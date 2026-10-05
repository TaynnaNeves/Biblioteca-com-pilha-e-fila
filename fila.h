#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    char nome[50];
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
void entrarFila(Fila *fila, char nome[]);
void consultarFila(Fila *fila);
void sairFila(Fila *fila);
void mostrarFila(Fila *fila);
void liberarFila(Fila *fila);

#endif