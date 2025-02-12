#include <stdio.h>
#include <string.h>

#define MAX 100

int LCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[MAX][MAX]; // Tabela DP

    // Preenchendo a tabela
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    return dp[m][n]; // Retorna o tamanho da LCS
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";

    printf("Comprimento da LCS: %d\n", LCS(X, Y));
    return 0;
}
