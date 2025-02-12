/*
2) Um palíndromo é uma palavra, frase ou qualquer sequência de caracteres que pode ser
lida tanto da esquerda para a direita quanto da direita para a esquerda. Por exemplo,
"arara" é um palíndromo, enquanto "araras" não é. Escreva um algoritmo de
programação dinâmica para encontrar o palíndromo mais longo que é uma subsequência
de uma dada sequência de caracteres. Assim, dada a entrada "character", seu algoritmo
deve retornar "carac". Faça uma análise do consumo de tempo de sua solução.

# Explicação do Algoritmo
Utilizamos Programação Dinâmica (PD) para resolver esse problema de maneira eficiente:

    Definimos uma matriz dp[i][j], onde:
        dp[i][j] armazena o tamanho da subsequência palindrômica mais longa no intervalo da string s[i...j].
    Casos base:
        Uma única letra sempre é um palíndromo → dp[i][i] = 1.
    Recorrência:
        Se s[i] == s[j], então dp[i][j] = 2 + dp[i+1][j-1] (se os extremos forem iguais, expandimos a subsequência palindrômica).
        Caso contrário, dp[i][j] = max(dp[i+1][j], dp[i][j-1]) (tomamos a melhor solução entre ignorar s[i] ou s[j]).
    A resposta final estará em dp[0][n-1], onde n é o tamanho da string.
Código em C
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

// Função para encontrar o tamanho da subsequência palindrômica mais longa
int lps(char *s, int n) {
    int dp[MAX][MAX] = {0};

    // Todas as substrings de um único caractere são palíndromos de tamanho 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Preenchendo a tabela dp para substrings de tamanhos maiores
    for (int tam = 2; tam <= n; tam++) {
        for (int i = 0; i < n - tam + 1; i++) {
            int j = i + tam - 1;
            if (s[i] == s[j] && tam == 2) {
                dp[i][j] = 2; // Caso base para substrings de tamanho 2
            } else if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1]; // Se os extremos são iguais, expande o palíndromo
            } else {
                dp[i][j] = (dp[i + 1][j] > dp[i][j - 1]) ? dp[i + 1][j] : dp[i][j - 1]; // Melhor dos dois casos
            }
        }
    }

    return dp[0][n - 1]; // Tamanho do maior palíndromo na string inteira
}

// Função auxiliar para reconstruir o palíndromo mais longo
void reconstruirPalindromo(char *s, int n, int dp[MAX][MAX], char *res) {
    int i = 0, j = n - 1;
    int start = 0, end = dp[0][n - 1] - 1;

    while (i <= j) {
        if (s[i] == s[j]) {
            res[start++] = s[i]; // Adiciona no início
            res[end--] = s[j];   // Adiciona no final
            i++;
            j--;
        } else if (dp[i + 1][j] > dp[i][j - 1]) {
            i++;
        } else {
            j--;
        }
    }
    res[dp[0][n - 1]] = '\0'; // Finaliza string
}

// Função principal
int main() {
    char s[MAX];
    printf("Digite uma string: ");
    scanf("%s", s);

    int n = strlen(s);
    int dp[MAX][MAX] = {0};

    // Calcula o tamanho do maior palíndromo
    int tamanho = lps(s, n);

    // Reconstruindo a subsequência palindrômica
    char res[MAX];
    reconstruirPalindromo(s, n, dp, res);

    printf("Maior subsequência palindrômica: %s\n", res);
    printf("Tamanho: %d\n", tamanho);

    return 0;
}

/*
Análise de Complexidade
A complexidade de tempo da solução é O(n²), pois:
    Preenchemos a matriz dp[i][j] para todos os intervalos possíveis de s[i...j], o que requer O(n²) operações.
    A reconstrução do palíndromo a partir da matriz também é O(n), mas isso não afeta a complexidade principal.
A complexidade de espaço também é O(n²), pois armazenamos os valores da matriz dp.
*/