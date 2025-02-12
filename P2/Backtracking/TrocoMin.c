#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000      // Limite máximo para o valor de troco (para o tamanho dos arrays de solução)
#define INF 1000000     // Valor grande para inicializar a melhor solução

int coins[MAX_N];       // Array que guarda os valores das moedas disponíveis
int m;                  // Número de moedas disponíveis
int bestCount = INF;    // Número mínimo de moedas encontrado (solução ótima)
int bestSolution[MAX_N]; // Array que armazenará a solução ótima (os valores das moedas utilizados)
int currentSolution[MAX_N]; // Array que armazena a solução corrente durante o backtracking

/* Função de comparação para qsort: ordena em ordem decrescente */
int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

/*
 * Função backtrack:
 *   remaining: valor restante a ser composto
 *   count: quantidade de moedas já utilizadas na solução corrente
 *   start: índice a partir do qual as moedas podem ser escolhidas (para evitar duplicatas)
 *
 * A cada chamada, se remaining == 0, significa que a soma das moedas escolhidas atinge o troco desejado.
 * Se o número de moedas usadas (count) for menor que a melhor solução encontrada até o momento,
 * a solução corrente é salva como a melhor.
 */
void backtrack(int remaining, int count, int start) {
    // Caso base: troco exatamente atingido
    if (remaining == 0) {
        for (int i = 0; i < count; i++) {
            printf("%d ", currentSolution[i]);
        }
        
        if (count < bestCount) {
            bestCount = count;
            for (int i = 0; i < count; i++) {
                bestSolution[i] = currentSolution[i];
            }
        }
        printf("\n");
        return;
    }
    
    // Poda: se já usamos moedas em número >= melhor solução encontrada, interrompe
    if (count >= bestCount)
        return;
    
    // Para cada moeda a partir do índice 'start' (permitindo reutilização da mesma moeda)
    for (int i = start; i < m; i++) {
        if (coins[i] <= remaining) {  // Se a moeda pode ser utilizada (não ultrapassa o valor restante)
            currentSolution[count] = coins[i];
            // Permite reutilizar a mesma moeda: chama recursivamente com i (não i+1)
            backtrack(remaining - coins[i], count + 1, i);
        }
    }
}

int main() {
    int n;
    
    // Entrada: valor do troco (em centavos)
    printf("Digite o valor do troco (em centavos): ");
    scanf("%d", &n);
    
    // Entrada: número de moedas disponíveis
    printf("Digite o número de moedas disponíveis: ");
    scanf("%d", &m);
    
    // Entrada: valores das moedas (em centavos)
    printf("Digite os valores das moedas (em centavos):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &coins[i]);
    }
    
    // Ordena as moedas em ordem decrescente para melhorar o desempenho (poda)
    qsort(coins, m, sizeof(int), cmp);
    
    // Inicia o processo de backtracking
    backtrack(n, 0, 0);
    
    // Exibe o resultado
    if (bestCount == INF) {
        printf("Não há solução.\n");
    } else {
        printf("Número mínimo de moedas: %d\n", bestCount);
        printf("Conjunto das moedas utilizadas: ");
        for (int i = 0; i < bestCount; i++) {
            printf("%d ", bestSolution[i]);
        }
        printf("\n");
    }
    
    return 0;
}
