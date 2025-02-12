#include <stdio.h>
#include <limits.h>

// Função auxiliar para calcular o mínimo
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Função auxiliar que utiliza memoização
int MinBoxesAux(int demand, int sizes[], int m, int memo[])
{
    if (memo[demand] >= 0)
    { // Verifica se já foi calculado
        return memo[demand];
    }

    int result;
    if (demand == 0)
    { // Caso base: demanda atendida
        result = 0;
    }
    else
    {
        result = INT_MAX;
        for (int i = 0; i < m; i++)
        { // Itera sobre os tamanhos disponíveis
            if (sizes[i] <= demand)
            { // Só tenta com tamanhos que cabem na demanda restante
                result = min(result, 1 + MinBoxesAux(demand - sizes[i], sizes, m, memo));
            }
        }
    }

    memo[demand] = result; // Armazena o resultado
    return result;
}

// Função principal que inicializa a memoização e chama a função auxiliar
int MinBoxes(int n, int sizes[], int m)
{
    int memo[n + 1]; // Array de memoização
    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1; // Inicializa como não calculado
    }
    return MinBoxesAux(n, sizes, m, memo);
}

int main()
{
    int n, m;

    // Entrada de dados
    // printf("Digite a demanda (n) e o número de tamanhos de caixas disponíveis (m): ");
    scanf("%d %d", &n, &m);

    int sizes[m];
    // printf("Digite os tamanhos das caixas: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sizes[i]);
    }

    // Chamada da função principal
    int result = MinBoxes(n, sizes, m);
    // printf("A quantidade mínima de caixas necessárias: %d\n", result);
    printf("%d\n", result);

    return 0;
}
