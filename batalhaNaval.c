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
    int linhaHorizontal = 2; // Linha inicial do navio horizontal
    int colunaHorizontal = 4; // Coluna inicial
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3; // Marca as posições
    }

    // Posicionando o navio verticalmente
    int linhaVertical = 5; // Linha inicial do navio vertical
    int colunaVertical = 7; // Coluna inicial
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3; // Marca as posições
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da posição
        }
        printf("\n"); // Nova linha para cada linha do tabuleiro
    }

    return 0;
}
