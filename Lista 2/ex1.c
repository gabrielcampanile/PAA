// Projeto e Análise de Algoritmos
// Lista de Exercı́cios 2

/* 1) Considere o problema das 8 rainhas: em um tabuleiro 8x8 de xadrez é possível
encontrar diferentes formas de posicionar 8 rainhas de forma que nenhuma rainha
consiga atacar outra rainha em apenas 1 movimento. A rainha é uma peça de xadrez
que a cada movimento pode se movimentar em múltiplas casas e em diferentes direções:
vertical, horizontal e em diagonal. Projete um algoritmo por backtracking que
encontre uma solução para o problema das 8 rainhas de forma eficiente.
Escreva o pseudo-código do algoritmo.

Pseudocódigo - Problema das 8 Rainhas (Backtracking)
Função éSeguro(tabuleiro, linha, coluna):
    Para i de 0 até coluna:
        Se tabuleiro[linha][i] == 1:
            Retornar Falso

    Para i, j de linha-1, coluna-1 até 0, 0 (diagonal superior esquerda):
        Se tabuleiro[i][j] == 1:
            Retornar Falso

    Para i, j de linha+1, coluna-1 até 7, 0 (diagonal inferior esquerda):
        Se tabuleiro[i][j] == 1:
            Retornar Falso

    Retornar Verdadeiro

Função resolver8Rainhas(tabuleiro, coluna):
    Se coluna >= 8:
        Retornar Verdadeiro

    Para cada linha de 0 até 7:
        Se éSeguro(tabuleiro, linha, coluna):
            tabuleiro[linha][coluna] = 1

            Se resolver8Rainhas(tabuleiro, coluna+1) == Verdadeiro:
                Retornar Verdadeiro

            tabuleiro[linha][coluna] = 0 (backtrack)

    Retornar Falso

Função principal:
    Criar tabuleiro 8x8 preenchido com 0
    Se resolver8Rainhas(tabuleiro, 0) == Verdadeiro:
        Imprimir tabuleiro
    Senão:
        Imprimir "Não há solução"


Explicação
1. Função éSeguro: verifica se uma rainha pode ser colocada em uma posição sem ser atacada por outras.
     Verifica a linha atual para a esquerda.
     Verifica a diagonal superior esquerda.
     Verifica a diagonal inferior esquerda.
2. Função resolver8Rainhas: tenta colocar uma rainha em cada coluna e chama recursivamente a função para resolver as próximas colunas.
     Se conseguir colocar todas as 8 rainhas, retorna verdadeiro.
     Caso contrário, faz backtracking (desfaz a última jogada e tenta outra posição).
3. Função principal: inicializa o tabuleiro e chama a função para resolver o problema.
*/
// Aqui está a implementação do Problema das 8 Rainhas usando Backtracking em C:

#include <stdio.h>

#define N 8

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para verificar se a posição é segura
int ehSeguro(int tabuleiro[N][N], int linha, int coluna)
{
    int i, j;

    // Verifica a linha na esquerda
    for (i = 0; i < coluna; i++)
    {
        if (tabuleiro[linha][i])
            return 0;
    }

    // Verifica a diagonal superior esquerda
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
    {
        if (tabuleiro[i][j])
            return 0;
    }

    // Verifica a diagonal inferior esquerda
    for (i = linha, j = coluna; i < N && j >= 0; i++, j--)
    {
        if (tabuleiro[i][j])
            return 0;
    }

    return 1;
}

// Função para resolver o problema recursivamente
int resolver8Rainhas(int tabuleiro[N][N], int coluna)
{
    // Se todas as colunas foram preenchidas, solução encontrada
    if (coluna >= N)
        return 1;

    // Tenta colocar a rainha em cada linha desta coluna
    for (int i = 0; i < N; i++)
    {
        if (ehSeguro(tabuleiro, i, coluna))
        {
            tabuleiro[i][coluna] = 1; // Coloca a rainha

            if (resolver8Rainhas(tabuleiro, coluna + 1))
                return 1; // Recursão

            tabuleiro[i][coluna] = 0; // Backtracking (remove a rainha)
        }
    }

    return 0; // Se nenhuma posição foi válida, retorna falso
}

// Função principal
int main()
{
    int tabuleiro[N][N] = {0};

    if (resolver8Rainhas(tabuleiro, 0))
    {
        printf("Solução encontrada:\n");
        imprimirTabuleiro(tabuleiro);
    }
    else
    {
        printf("Não há solução\n");
    }

    return 0;
}

/*
Explicação do Código
1. imprimirTabuleiro: Mostra o tabuleiro na saída.
2. ehSeguro: Verifica se uma rainha pode ser colocada sem ser atacada.
    Checa a linha esquerda.
    Checa a diagonal superior esquerda.
    Checa a diagonal inferior esquerda.
3. resolver8Rainhas:
    Tenta colocar uma rainha em cada linha de uma coluna.
    Se conseguir colocar todas as 8 rainhas, retorna sucesso.
    Caso contrário, usa backtracking para remover a rainha e testar outra posição.
4. main:
    Inicializa o tabuleiro.
    Chama resolver8Rainhas e imprime o resultado.
*/