/*
3) Seja um conjunto S de inteiros e um inteiro positivo k. Considere o problema 
de se encontrar um subconjunto X⊆S de tamanho k cuja soma seja máxima entre todos
possíveis subconjuntos de S.
a) Forneça um algoritmo guloso para o problema.
b) Mostre que o algoritmo encontra a solução ótima. Caso contrário, mostre um
contra-exemplo.

# Parte (a): Algoritmo Guloso
A abordagem gulosa para este problema é simples:

    Ordenar o conjunto 𝑆 em ordem decrescente.
    Selecionar os 𝑘 maiores elementos.

Pseudo-código do Algoritmo Guloso

Algoritmo Guloso_Max_Subconjunto(S, k):
    Ordene S em ordem decrescente
    X ← os k primeiros elementos de S
    Retorne X

Implementação em C
*/

#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort (ordem decrescente)
int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Função para encontrar os k maiores elementos
void gulosoMaxSubconjunto(int S[], int n, int k) {
    // Ordena o array em ordem decrescente
    qsort(S, n, sizeof(int), cmp);

    // Seleciona os k primeiros elementos
    printf("Subconjunto escolhido: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int S[] = {4, 2, 7, 1, 9, 3, 8};
    int k = 3;
    int n = sizeof(S) / sizeof(S[0]);

    gulosoMaxSubconjunto(S, n, k);

    return 0;
}

/*Exemplo de Entrada e Saída
Entrada:
    S = {4, 2, 7, 1, 9, 3, 8}
    k = 3
Saída:
    Subconjunto escolhido: 9 8 7
A soma é 9+8+7=24, que é a maior soma possível.
*/

/*
# Parte (b): O Algoritmo é Ótimo?
Sim! O algoritmo guloso sempre retorna uma solução ótima, pois:

    1. A soma de um subconjunto depende apenas dos valores individuais de seus elementos.
    2.  Para maximizar a soma, devemos escolher os 𝑘 maiores números, pois qualquer outro 
    subconjunto teria pelo menos um número menor, resultando em uma soma inferior.

Prova por contradição:
    Se houvesse um subconjunto 𝑋′ de tamanho 𝑘 cuja soma fosse maior que a soma do 
    conjunto retornado pelo algoritmo, isso significaria que 𝑋′ contém um elemento 
    menor que algum dos 𝑘 maiores elementos escolhidos. Mas substituir esse elemento 
    por um dos maiores sempre aumentaria a soma, contradizendo a suposição de que 
    𝑋′ era ótimo.

Conclusão:
O algoritmo guloso resolve este problema de forma ótima em O(n log n) devido à ordenação.*/