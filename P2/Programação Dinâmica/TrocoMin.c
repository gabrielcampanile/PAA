#include <stdio.h>
#include <limits.h>

#define MAX_N 1000  // Define um valor máximo para n

int minCoins(int coins[], int m, int n) {
    int dp[MAX_N + 1];

    // Inicializa todos os valores como um número grande
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0; // Base: 0 centavos precisa de 0 moedas

    // Resolve o problema para todos os valores até n
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : (dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[n] == INT_MAX ? -1 : dp[n]; // Retorna -1 se não for possível dar troco
}

int main() {
    int coins[] = {1, 5, 10, 25}; // Exemplo: moedas de 1, 5, 10 e 25 centavos
    int n = 63; // Valor a ser devolvido
    int m = sizeof(coins) / sizeof(coins[0]);

    printf("Mínimo de moedas necessárias: %d\n", minCoins(coins, m, n));

    return 0;
}
