#include <stdio.h>
#include <limits.h>

int main()
{
    int n, m; // n: demanda do cliente, m: número de tamanhos de caixas disponíveis
    scanf("%d %d", &n, &m);

    int caixas[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &caixas[i]);
    }

    // Vetor para armazenar o número mínimo de caixas para cada valor de demanda
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = INT_MAX; // Inicializa com um valor muito grande
    }
    dp[0] = 0; // Zero caixas são necessárias para atender demanda 0

    // Preenchendo o vetor dp
    for (int i = 0; i < m; i++)
    {
        for (int j = caixas[i]; j <= n; j++)
        {
            if (dp[j - caixas[i]] != INT_MAX)
            {
                dp[j] = dp[j] < dp[j - caixas[i]] + 1 ? dp[j] : dp[j - caixas[i]] + 1;
            }
        }
    }

    // A resposta está em dp[n], se for diferente de INT_MAX
    if (dp[n] == INT_MAX)
    {
        printf("-1\n"); // Não é possível atender exatamente a demanda
    }
    else
    {
        printf("%d\n", dp[n]);
    }

    return 0;
}