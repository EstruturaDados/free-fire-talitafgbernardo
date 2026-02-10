#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char nome[30];
    int prioridade;
} Item;

int main() {

    Item mochila[MAX];
    int total = 0;

    // Cadastro
    for (int i = 0; i < 5; i++) {
        printf("Nome: ");
        scanf(" %[^\n]", mochila[i].nome);

        printf("Prioridade: ");
        scanf("%d", &mochila[i].prioridade);

        total++;
    }

    // Ordenacao por nome (Insertion Sort)
    for (int i = 1; i < total; i++) {
        Item aux = mochila[i];
        int j = i - 1;

        while (j >= 0 && strcmp(mochila[j].nome, aux.nome) > 0) {
            mochila[j + 1] = mochila[j];
            j--;
        }
        mochila[j + 1] = aux;
    }

    printf("\nItens ordenados:\n");
    for (int i = 0; i < total; i++) {
        printf("%s - %d\n", mochila[i].nome, mochila[i].prioridade);
    }

    return 0;
}
