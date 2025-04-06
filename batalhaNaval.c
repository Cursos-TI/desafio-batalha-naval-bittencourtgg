#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com 0 (representando água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionando o navio horizontalmente
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posicionando o navio verticalmente
    int linhaVertical = 5;
    int colunaVertical = 7;
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Posicionando o navio na diagonal principal (linha = coluna)
    int linhaDiagonal1 = 0; // Linha inicial
    int colunaDiagonal1 = 0; // Coluna inicial
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3;
    }

    // Posicionando o navio na diagonal secundária (linha + coluna = 9)
    int linhaDiagonal2 = 7; // Linha inicial
    int colunaDiagonal2 = 2; // Coluna inicial
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaDiagonal2 - i][colunaDiagonal2 + i] = 3;
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
