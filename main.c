#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"

int main() {

    Fila fila;
    Pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int opcao;
    char entrada[20];
    char nome[50];
    char livro[100];

    do {

        printf("\n==============================\n");
        printf("       SISTEMA DE BIBLIOTECA \n");
        printf("==============================\n");
        printf("1 - Colocar pessoa na fila\n");
        printf("2 - Atender proxima pessoa\n");
        printf("3 - Consultar proxima pessoa\n");
        printf("4 - Mostrar fila\n");
        printf("5 - Colocar livro na pilha\n");
        printf("6 - Retirar livro da pilha\n");
        printf("7 - Consultar livro do topo\n");
        printf("8 - Mostrar pilha\n");
        printf("9 - Verificar se a fila esta vazia\n");
        printf("10 - Verificar se a pilha esta vazia\n");
        printf("0 - Sair\n");
        printf("==============================\n");
        printf("Escolha uma opcao: ");

        fgets(entrada, sizeof(entrada), stdin);
        if (sscanf(entrada, "%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            opcao = -1;
        continue;
}

        switch (opcao) {

            case 1:
                printf("Digite o nome da pessoa, por favor: ");
                fgets(nome, sizeof(nome), stdin);

                nome[strcspn(nome, "\n")] = '\0';

                entrarFila(&fila, nome);
                break;

            case 2:
                sairFila(&fila);
                break;

            case 3:
                consultarFila(&fila);
                break;

            case 4:
                mostrarFila(&fila);
                break;

            case 5:
                printf("Digite o nome do livro, por favor: ");
                fgets(livro, sizeof(livro), stdin);

                livro[strcspn(livro, "\n")] = '\0';

                empilharLivro(&pilha, livro);
                break;

            case 6:
                desempilharLivro(&pilha);
                break;

            case 7:
                consultarPilha(&pilha);
                break;

            case 8:
                mostrarPilha(&pilha);
                break;

            case 9:
                if (filaVazia(&fila)) {
                    printf("Deu sorte, A fila esta vazia.\n");
                } else {
                    printf("A fila NAO esta vazia.\n");
                }
                break;

            case 10:
                if (pilhaVazia(&pilha)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha NAO esta vazia.\n");
                }
                break;

            case 0:
                printf("Tchau. Encerrando o sistema... \n");
                break;

            default:
                printf("Opcao invalida. Escolha uma opçao valida\n");
        }

    } while (opcao != 0);

    liberarFila(&fila);
    liberarPilha(&pilha);

    printf("Memoria liberada. Programa encerrado.\n");

    return 0;
}