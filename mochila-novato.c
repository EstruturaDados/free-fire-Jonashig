#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

void exibirMenu(int contador) {
    printf("=====================================\n");
    printf(" MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
    printf("=====================================\n");
    printf("Itens na Mochila: %d/%d\n\n", contador, MAX_ITENS);

    printf("1. Adicionar item (Loot)\n");
    printf("2. Remover Item\n");
    printf("3. Listar itens na mochila\n");
    printf("0. Sair\n");
    printf("-------------------------------------------------------------\n");
    printf("Escolha uma opção: ");
}

// ------------------------------------
// Inserir item
// ------------------------------------
void inserirItem(Item mochila[], int *contador) {
    if (*contador >= MAX_ITENS) {
        printf("\nA mochila está cheia! (%d/%d)\n", *contador, MAX_ITENS);
        pausar();
        return;
    }

    printf("\n--- ADICIONAR ITEM (LOOT) ---\n");

    printf("Nome do item: ");
    scanf(" %[^\n]", mochila[*contador].nome);

    printf("Tipo do item: ");
    scanf(" %[^\n]", mochila[*contador].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*contador].quantidade);

    (*contador)++;

    printf("\nItem adicionado com sucesso!\n");
    pausar();
}

// ------------------------------------
// Remover item
// ------------------------------------
void removerItem(Item mochila[], int *contador) {
    if (*contador == 0) {
        printf("\nA mochila está vazia! Nada para remover.\n");
        pausar();
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja remover: ");
    scanf(" %[^\n]", nomeBusca);

    int i, pos = -1;

    for (i = 0; i < *contador; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nItem não encontrado!\n");
        pausar();
        return;
    }

    for (i = pos; i < *contador - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*contador)--;

    printf("\nItem removido com sucesso!\n");
    pausar();
}

// ------------------------------------
// Listar itens formato planilha
// ------------------------------------
void listarItens(Item mochila[], int contador) {
    if (contador == 0) {
        printf("\nA mochila está vazia!\n");
        pausar();
        return;
    }

    printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", contador, MAX_ITENS);
    printf("---------------------------------------------\n");
    printf("NOME           | TIPO         | QUANTIDADE\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < contador; i++) {
        printf("%-14s | %-12s | %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }

    printf("---------------------------------------------\n");

    pausar();
}


// ------------------------------------
// PROGRAMA PRINCIPAL
// ------------------------------------
int main() {
    Item mochila[MAX_ITENS];
    int contador = 0;
    int opcao;

    do {
        exibirMenu(contador);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &contador);
                break;
            case 2:
                removerItem(mochila, &contador);
                break;
            case 3:
                listarItens(mochila, contador);
                break;
            case 0:
                printf("\nSaindo da Ilha...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                pausar();
        }

    } while (opcao != 0);

    return 0;
}
