#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int tamanho;
} Lista;

void inicializar(Lista *lista) {
    lista->tamanho = 0;
}

void adicionar(Lista *lista, int valor) {
    if (lista->tamanho < TAMANHO_MAX) {
        lista->dados[lista->tamanho++] = valor;
    } else {
        printf("Erro: Lista cheia\n");
    }
}

void inserir(Lista *lista, int indice, int valor) {
    if (lista->tamanho < TAMANHO_MAX && indice <= lista->tamanho && indice >= 0) {
        for (int i = lista->tamanho; i > indice; i--) {
            lista->dados[i] = lista->dados[i-1];
        }
        lista->dados[indice] = valor;
        lista->tamanho++;
    } else {
        printf("Erro: Não é possível inserir\n");
    }
}

int remover_ultimo(Lista *lista) {
    if (lista->tamanho > 0) {
        return lista->dados[--lista->tamanho];
    } else {
        printf("Erro: Lista vazia\n");
        return -1;
    }
}

void remover_indice(Lista *lista, int indice) {
    if (indice < lista->tamanho && indice >= 0) {
        for (int i = indice; i < lista->tamanho - 1; i++) {
            lista->dados[i] = lista->dados[i+1];
        }
        lista->tamanho--;
    } else {
        printf("Erro: Índice inválido\n");
    }
}

int contar(Lista *lista, int valor) {
    int contagem = 0;
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            contagem++;
        }
    }
    return contagem;
}

int indice(Lista *lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->dados[i] == valor) {
            return i;
        }
    }
    return -1;
}

void inverter(Lista *lista) {
    for (int i = 0; i < lista->tamanho / 2; i++) {
        int temp = lista->dados[i];
        lista->dados[i] = lista->dados[lista->tamanho - i - 1];
        lista->dados[lista->tamanho - i - 1] = temp;
    }
}

void ordenar(Lista *lista) {
    for (int i = 0; i < lista->tamanho - 1; i++) {
        for (int j = 0; j < lista->tamanho - i - 1; j++) {
            if (lista->dados[j] > lista->dados[j+1]) {
                int temp = lista->dados[j];
                lista->dados[j] = lista->dados[j+1];
                lista->dados[j+1] = temp;
            }
        }
    }
}

void imprimir_lista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

int main() {
    Lista lista;
    inicializar(&lista);

    adicionar(&lista, 5);
    adicionar(&lista, 3);
    adicionar(&lista, 7);
    printf("Lista inicial: ");
    imprimir_lista(&lista);

    printf("Contagem de 3: %d\n", contar(&lista, 3));
    printf("Índice de 7: %d\n", indice(&lista, 7));

    inserir(&lista, 1, 2);
    printf("Lista com inserção: ");
    imprimir_lista(&lista);

    int removido = remover_ultimo(&lista);
    printf("Elemento removido: %d\n", removido);
    printf("Lista com remoção: ");
    imprimir_lista(&lista);

    remover_indice(&lista, 1);
    printf("Lista com remoção no índice: ");
    imprimir_lista(&lista);

    inverter(&lista);
    printf("Lista com reversão: ");
    imprimir_lista(&lista);

    ordenar(&lista);
    printf("Lista com ordenação: ");
    imprimir_lista(&lista);

    return 0;
}