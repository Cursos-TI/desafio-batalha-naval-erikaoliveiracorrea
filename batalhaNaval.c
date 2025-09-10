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
    int linhaHorizontal = 2;  // linha 3 índice 2
    int colunaHorizontal = 0; // começa na coluna A índice 0
    for (int i = 0; i < casaDoNavio; i++)
    {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // linhas vertiacal 5, 6 e 7 ===
    int linhaVertical = 4;  // linha 5 índice 4
    int colunaVertical = 2; // começa na coluna C índice 2
    for (int i = 0; i < casaDoNavio; i++)
    {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
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
