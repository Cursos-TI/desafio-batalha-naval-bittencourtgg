#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define HABILIDADE 5
#define VALOR_HABILIDADE 5 // Representa as áreas de efeito no tabuleiro
#define VALOR_NAVIO 3       // Representa os navios no tabuleiro

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para aplicar matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[HABILIDADE][HABILIDADE], int origemLinha, int origemColuna) {
    int offset = HABILIDADE / 2; // Centro da matriz

    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            int linha = origemLinha + i - offset;
            int coluna = origemColuna + j - offset;

            // Aplica habilidade dentro dos limites e sem sobrescrever navios
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != VALOR_NAVIO) {
                    tabuleiro[linha][coluna] = VALOR_HABILIDADE;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro com símbolos
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Legenda: ~ Água | H Habilidade | N Navio\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            switch (tabuleiro[i][j]) {
                case 0: printf("~ "); break;
                case VALOR_HABILIDADE: printf("H "); break;
                case VALOR_NAVIO: printf("N "); break;
                default: printf("? "); break;
            }
        }
        printf("\n");
    }
}

// Função para criar matriz de habilidade em forma de cone
void criarCone(int habilidade[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            habilidade[i][j] = (j >= HABILIDADE / 2 - i && j <= HABILIDADE / 2 + i) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em forma de cruz
void criarCruz(int habilidade[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            habilidade[i][j] = (i == HABILIDADE / 2 || j == HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int habilidade[HABILIDADE][HABILIDADE]) {
    for (int i = 0; i < HABILIDADE; i++) {
        for (int j = 0; j < HABILIDADE; j++) {
            habilidade[i][j] = (abs(HABILIDADE / 2 - i) + abs(HABILIDADE / 2 - j) <= HABILIDADE / 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios no tabuleiro
    tabuleiro[2][2] = VALOR_NAVIO;
    tabuleiro[2][3] = VALOR_NAVIO;
    tabuleiro[2][4] = VALOR_NAVIO;
    tabuleiro[5][5] = VALOR_NAVIO;
    tabuleiro[6][5] = VALOR_NAVIO;
    tabuleiro[7][5] = VALOR_NAVIO;

    // Matrizes de habilidade
    int cone[HABILIDADE][HABILIDADE];
    int cruz[HABILIDADE][HABILIDADE];
    int octaedro[HABILIDADE][HABILIDADE];

    // Criação das habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicação das habilidades
    aplicarHabilidade(tabuleiro, cone, 4, 4);       // Cone em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 2, 7);       // Cruz em (2,7)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);   // Octaedro em (7,2)

    // Exibição do resultado final
    printf("Tabuleiro de Batalha Naval com habilidades aplicadas:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

