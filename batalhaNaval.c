#include <stdio.h>

int main()
{
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

    // Letras para as colunas (A até J)
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // quantidade de casas dos navios
    int casaDoNavio = 3;

    // linhas Horizontal
    int linhaHorizontal = 8;  // linha 9 índice 8
    int colunaHorizontal = 1; // coluna B índice 1
    for (int i = 0; i < casaDoNavio; i++)
    {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // linhas vertiacal
    int linhaVertical = 4;  // linha 5 índice 4
    int colunaVertical = 2; // começa na coluna C índice 2
    for (int i = 0; i < casaDoNavio; i++)
    {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // diagonal
    int linhaDiag1 = 0;  // linha 1 índice 0
    int colunaDiag1 = 0; // coluna A índice 0
    for (int i = 0; i < casaDoNavio; i++)
    {
        tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = 3;
    }

    // diagonal
    int linhaDiag2 = 0;  // linha 1 índice 0
    int colunaDiag2 = 9; // coluna J índice 9
    for (int i = 0; i < casaDoNavio; i++)
    {
        tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = 3;
    }

    printf("TABULEIRO BATALHA NAVAL\n\n");

    // colunas A até J
    printf("   ");
    for (int c = 0; c < 10; c++)
    {
        printf("%c ", letras[c]);
    }
    printf("\n");

    // Exibição das linhas com números 1 até 10
    for (int i = 0; i < 10; i++)
    {
        printf("%-2d ", i + 1); // número da linha
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]); // tudo 0 (água)
        }
        printf("\n");
    }

    return 0;
}
