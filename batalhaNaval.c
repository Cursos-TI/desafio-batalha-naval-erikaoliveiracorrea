#include <stdio.h>

int main()
{
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[10][10] = {0};

   
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // Coordenadas iniciais dos navios
    // linha = índice da linha (0 = primeira linha)
    int linhaNavio1 = 2, colunaNavio1 = 1; // Navio 1 (horizontal)
    int linhaNavio2 = 4, colunaNavio2 = 2; // Navio 2 (vertical)

    // Posiciona o Navio 1 (horizontal)
    for (int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
    }

    // Posiciona o Navio 2 (vertical)
    for (int i = 0; i < tamanhoNavio; i++)
    {
        tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
    }

  
    printf("TABULEIRO BATALHA NAVAL\n\n");

    //colunas (A até J)
    printf("   ");
    for (int c = 0; c < 10; c++)
    {
        printf("%c ", letras[c]);
    }
    printf("\n");

    // Exibição das linhas com números (1 até 10)
    for (int i = 0; i < 10; i++)
    {
        printf("%-2d ", i + 1); // número da linha
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
