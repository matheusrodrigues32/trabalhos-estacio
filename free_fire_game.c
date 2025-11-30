#include <stdio.h>
#include <string.h>

// Definindo a estrutura para representar os itens no inventário
typedef struct {
    char nome[50];
    char tipo[20];  // Exemplo: "arma", "alimento", "ferramenta"
    int prioridade;  // Prioridade do item, usada para ordenação
} Item;

// Função para inserir itens no inventário
void inserir_item(Item *inventario, Item item, int *qtd) {
    inventario[*qtd] = item;
    (*qtd)++;
}

// Função de ordenação (Selection Sort) do inventário por prioridade
void ordenar_inventario(Item *inventario, int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (inventario[i].prioridade < inventario[j].prioridade) {
                // Troca de itens
                Item temp = inventario[i];
                inventario[i] = inventario[j];
                inventario[j] = temp;
            }
        }
    }
}

// Busca binária iterativa para procurar um item pelo nome
int busca_binaria(Item *inventario, int qtd, char *nome) {
    int inicio = 0, fim = qtd - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (strcmp(inventario[meio].nome, nome) == 0) {
            return meio;  // Item encontrado
        } else if (strcmp(inventario[meio].nome, nome) < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;  // Item não encontrado
}

// Busca binária recursiva para procurar um item pelo nome
int busca_binaria_recursiva(Item *inventario, int inicio, int fim, char *nome) {
    if (inicio > fim) return -1;

    int meio = (inicio + fim) / 2;
    if (strcmp(inventario[meio].nome, nome) == 0) {
        return meio;  // Item encontrado
    } else if (strcmp(inventario[meio].nome, nome) < 0) {
        return busca_binaria_recursiva(inventario, meio + 1, fim, nome);
    } else {
        return busca_binaria_recursiva(inventario, inicio, meio - 1, nome);
    }
}

// Função principal para testar o código
int main() {
    Item inventario[100];
    int qtd = 0;  // Quantidade de itens no inventário

    // Criando alguns itens para o inventário
    Item item1 = {"Espada", "Arma", 3};
    Item item2 = {"Comida", "Alimento", 2};
    Item item3 = {"Kit médico", "Ferramenta", 1};

    // Inserindo os itens no inventário
    inserir_item(inventario, item1, &qtd);
    inserir_item(inventario, item2, &qtd);
    inserir_item(inventario, item3, &qtd);

    // Ordenando o inventário por prioridade
    ordenar_inventario(inventario, qtd);

    // Exibindo os itens ordenados
    printf("Inventário ordenado por prioridade:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Item: %s, Tipo: %s, Prioridade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].prioridade);
    }

    // Buscando um item no inventário
    char nome_busca[50] = "Comida";
    int pos = busca_binaria(inventario, qtd, nome_busca);
    if (pos != -1) {
        printf("\nItem encontrado (busca binária iterativa): %s\n", inventario[pos].nome);
    } else {
        printf("\nItem não encontrado (busca binária iterativa).\n");
    }

    // Buscando um item usando busca binária recursiva
    pos = busca_binaria_recursiva(inventario, 0, qtd - 1, nome_busca);
    if (pos != -1) {
        printf("Item encontrado (busca binária recursiva): %s\n", inventario[pos].nome);
    } else {
        printf("Item não encontrado (busca binária recursiva).\n");
    }

    return 0;
}
