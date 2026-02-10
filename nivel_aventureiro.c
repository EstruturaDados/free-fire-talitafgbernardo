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
        printf("\n=== NIVEL AVENTUREIRO ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Listar itens\n");
        printf("3 - Buscar item pelo nome\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Nome: ");
            scanf(" %[^\n]", mochila[total].nome);

            printf("Tipo: ");
            scanf(" %[^\n]", mochila[total].tipo);

            printf("Quantidade: ");
            scanf("%d", &mochila[total].quantidade);

            total++;

        } else if (opcao == 2) {
            for (int i = 0; i < total; i++) {
                printf("\nNome: %s", mochila[i].nome);
                printf("\nTipo: %s", mochila[i].tipo);
                printf("\nQuantidade: %d\n", mochila[i].quantidade);
            }

        } else if (opcao == 3) {
            char nome[30];
            int achou = 0;

            printf("Nome para busca: ");
            scanf(" %[^\n]", nome);

            for (int i = 0; i < total; i++) {
                if (strcmp(mochila[i].nome, nome) == 0) {
                    printf("Item encontrado!\n");
                    achou = 1;
                    break;
                }
            }

            if (!achou) {
                printf("Item nao encontrado!\n");
            }
        }

    } while (opcao != 0);

    return 0;
}
