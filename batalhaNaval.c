#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

#define AGUA 0

// imprime o tabuleiro com índices 0-9
void imprimir_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    printf("   ");
    for (int c = 0; c < TAM_TABULEIRO; c++)
    {
        printf("%d ", c);
    }
    printf("\n");

    for (int linha = 0; linha < TAM_TABULEIRO; linha++)
    {
        printf("%d  ", linha);
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

// aplica forma geométrica no tabuleiro com número específico
void aplicar_forma(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                   int forma[TAM_HABILIDADE][TAM_HABILIDADE],
                   int linhaOrigem, int colunaOrigem,
                   int linhaCentro, int colunaCentro,
                   int numero)
{

    for (int linha = 0; linha < TAM_HABILIDADE; linha++)
    {
        for (int coluna = 0; coluna < TAM_HABILIDADE; coluna++)
        {
            if (forma[linha][coluna] == 1)
            {
                int posLinha = linhaOrigem + (linha - linhaCentro);
                int posColuna = colunaOrigem + (coluna - colunaCentro);

                if (posLinha >= 0 && posLinha < TAM_TABULEIRO &&
                    posColuna >= 0 && posColuna < TAM_TABULEIRO)
                {
                    tabuleiro[posLinha][posColuna] = numero;
                }
            }
        }
    }
}

int main()
{
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // inicializa com água
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
    }

    int centro = TAM_HABILIDADE / 2;

    // Triângulo (cone)
    int triangulo[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int l = 0; l < TAM_HABILIDADE; l++)
    {
        for (int c = 0; c < TAM_HABILIDADE; c++)
        {
            triangulo[l][c] = (c >= centro - l && c <= centro + l) ? 1 : 0;
        }
    }

    // Cruz
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int l = 0; l < TAM_HABILIDADE; l++)
    {
        for (int c = 0; c < TAM_HABILIDADE; c++)
        {
            cruz[l][c] = (l == centro || c == centro) ? 1 : 0;
        }
    }

    // Octógono (losango)
    int octogono[TAM_HABILIDADE][TAM_HABILIDADE];
    for (int l = 0; l < TAM_HABILIDADE; l++)
    {
        for (int c = 0; c < TAM_HABILIDADE; c++)
        {
            int distL = (l > centro) ? l - centro : centro - l;
            int distC = (c > centro) ? c - centro : centro - c;
            octogono[l][c] = (distL + distC <= centro) ? 1 : 0;
        }
    }

    // aplicar formas no tabuleiro com números diferentes
    aplicar_forma(tabuleiro, triangulo, 1, 3, 0, centro, 1);     // triângulo = 1
    aplicar_forma(tabuleiro, cruz, 4, 7, centro, centro, 2);     // cruz = 2
    aplicar_forma(tabuleiro, octogono, 6, 2, centro, centro, 3); // octógono = 3

    imprimir_tabuleiro(tabuleiro);

    return 0;
}
