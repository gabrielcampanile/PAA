#include <stdio.h>
#include <limits.h>

int trocoPD(int T, int moedas[], int n) {
    int dp[T+1];  
    dp[0] = 0;  

    for (int i = 1; i <= T; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (moedas[j] <= i && dp[i - moedas[j]] != INT_MAX) {
                dp[i] = (dp[i] < 1 + dp[i - moedas[j]]) ? dp[i] : 1 + dp[i - moedas[j]];
            }
        }
    }
    return dp[T];
}

int main() {
    int moedas[] = {10, 6, 1};
    int T = 12;
    int n = sizeof(moedas) / sizeof(moedas[0]);

    printf("Mínimo de moedas necessário: %d\n", trocoPD(T, moedas, n));
    return 0;
}

