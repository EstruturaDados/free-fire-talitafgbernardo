#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {

    Item mochila[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n=== NIVEL NOVATO - MOCHILA ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total >= MAX) {
                printf("Mochila cheia!\n");
            } else {
                printf("Nome: ");
                scanf(" %[^\n]", mochila[total].nome);

                printf("Tipo: ");
                scanf(" %[^\n]", mochila[total].tipo);

                printf("Quantidade: ");
                scanf("%d", &mochila[total].quantidade);

                total++;
                printf("Item adicionado!\n");
            }

        } else if (opcao == 2) {
            char nome[30];
            int encontrou = 0;

            printf("Nome do item para remover: ");
            scanf(" %[^\n]", nome);

            for (int i = 0; i < total; i++) {
                if (strcmp(mochila[i].nome, nome) == 0) {
                    for (int j = i; j < total - 1; j++) {
                        mochila[j] = mochila[j + 1];
                    }
                    total--;
                    encontrou = 1;
                    printf("Item removido!\n");
                    break;
                }
            }

            if (!encontrou) {
                printf("Item nao encontrado!\n");
            }

        } else if (opcao == 3) {
            if (total == 0) {
                printf("Mochila vazia!\n");
            } else {
                for (int i = 0; i < total; i++) {
                    printf("\nItem %d\n", i + 1);
                    printf("Nome: %s\n", mochila[i].nome);
                    printf("Tipo: %s\n", mochila[i].tipo);
                    printf("Quantidade: %d\n", mochila[i].quantidade);
                }
            }
        }

    } while (opcao != 0);

    return 0;
}
