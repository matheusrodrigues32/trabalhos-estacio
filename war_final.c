#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 6
#define MAX_JOGADORES 2

// ----------------------- STRUCTS --------------------------

typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Jogador;

typedef struct {
    char nome[30];
    int tropas;
    int dono; // índice do jogador
} Territorio;

// --------------------- FUNÇÕES ----------------------------

void cadastrarJogadores(Jogador *jogadores) {
    for (int i = 0; i < MAX_JOGADORES; i++) {
        printf("\n--- Cadastro do Jogador %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", jogadores[i].nome);

        printf("Cor: ");
        scanf(" %[^\n]", jogadores[i].cor);

        jogadores[i].tropas = 15;  
    }
}

void inicializarTerritorios(Territorio *t) {
    strcpy(t[0].nome, "Brasil");
    strcpy(t[1].nome, "Argentina");
    strcpy(t[2].nome, "Chile");
    strcpy(t[3].nome, "Peru");
    strcpy(t[4].nome, "Venezuela");
    strcpy(t[5].nome, "Colombia");

    // Distribui territórios entre os dois jogadores
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        t[i].tropas = 3;
        t[i].dono = i % MAX_JOGADORES;
    }
}

void listarTerritorios(Territorio *t, Jogador *j) {
    printf("\n=== Territórios ===\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("%s | Tropas: %d | Dono: %s\n",
               t[i].nome,
               t[i].tropas,
               j[t[i].dono].nome);
    }
}

void atacar(Territorio *t, Jogador *j) {
    int origem, alvo;

    printf("\n--- ATAQUE ---\n");
    listarTerritorios(t, j);

    printf("\nEscolha o território de ORIGEM (índice 0 a 5): ");
    scanf("%d", &origem);

    printf("Escolha o território ALVO (índice 0 a 5): ");
    scanf("%d", &alvo);

    if (origem < 0 || origem >= MAX_TERRITORIOS || alvo < 0 || alvo >= MAX_TERRITORIOS) {
        printf("Índices inválidos!\n");
        return;
    }

    if (t[origem].dono == t[alvo].dono) {
        printf("Você não pode atacar seu próprio território.\n");
        return;
    }

    if (t[origem].tropas < 2) {
        printf("Território de origem precisa ter pelo menos 2 tropas.\n");
        return;
    }

    int dadoAtk = (rand() % 6) + 1;
    int dadoDef = (rand() % 6) + 1;

    printf("\nDado Atacante: %d\n", dadoAtk);
    printf("Dado Defensor: %d\n", dadoDef);

    if (dadoAtk > dadoDef) {
        t[alvo].tropas--;

        printf("O defensor perdeu 1 tropa!\n");

        if (t[alvo].tropas == 0) {
            printf("TERRITÓRIO CONQUISTADO!\n");
            t[alvo].dono = t[origem].dono;
            t[alvo].tropas = 1;
            t[origem].tropas -= 1;
        }

    } else {
        printf("O atacante perdeu 1 tropa!\n");
        t[origem].tropas--;
    }
}

int verificarMissao(Jogador *j, Territorio *t) {
    // missão simples: dominar 3 territórios
    for (int i = 0; i < MAX_JOGADORES; i++) {
        int count = 0;
        for (int k = 0; k < MAX_TERRITORIOS; k++) {
            if (t[k].dono == i) count++;
        }
        if (count >= 4) return i;
    }
    return -1;
}

// ------------------------ MAIN ----------------------------

int main() {
    srand(time(NULL));

    Jogador *jogadores = (Jogador *) malloc(MAX_JOGADORES * sizeof(Jogador));
    Territorio *territorios = (Territorio *) malloc(MAX_TERRITORIOS * sizeof(Territorio));

    cadastrarJogadores(jogadores);
    inicializarTerritorios(territorios);

    int opcao, vencedor = -1;

    while (vencedor == -1) {
        printf("\n==== MENU ====\n");
        printf("1 - Listar Territórios\n");
        printf("2 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarTerritorios(territorios, jogadores);
                break;
            case 2:
                atacar(territorios, jogadores);
                vencedor = verificarMissao(jogadores, territorios);
                if (vencedor != -1) {
                    printf("\n\n=== JOGADOR %s VENCEU A MISSÃO! ===\n", jogadores[vencedor].nome);
                }
                break;
            case 0:
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    free(jogadores);
    free(territorios);

    return 0;
}
