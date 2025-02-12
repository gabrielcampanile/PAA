#include <stdio.h>
#include <string.h>

#define MAX 100

// Função para encontrar o comprimento da maior subsequência palindrômica
int longestPalindromeSubseq(char s[]) {
    int n = strlen(s);
    int dp[MAX][MAX];

    // Preenchendo a diagonal principal (cada letra sozinha é um palíndromo)
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Preenchendo a tabela para substrings de tamanho crescente
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1];
        }
    }

    return dp[0][n - 1]; // A resposta está no intervalo completo da string
}

// Função principal
int main() {
    char s[] = "character";
    printf("Maior subsequência palindrômica tem comprimento: %d\n", longestPalindromeSubseq(s));
    return 0;
}
