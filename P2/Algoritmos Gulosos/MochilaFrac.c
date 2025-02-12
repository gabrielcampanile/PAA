#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int peso;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    return ((Item*)b)->ratio - ((Item*)a)->ratio;
}

double knapsackFracionario(int W, Item itens[], int n) {
    qsort(itens, n, sizeof(Item), compare);
    double valorTotal = 0.0;

    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        if (itens[i].peso <= W) {
            valorTotal += itens[i].valor;
            W -= itens[i].peso;
        } else {
            valorTotal += itens[i].ratio * W;
            W = 0;
        }
    }
    return valorTotal;
}

int main() {
    Item itens[] = {{60, 3}, {100, 2}, {120, 4}};
    int W = 5;
    int n = sizeof(itens) / sizeof(itens[0]);

    for (int i = 0; i < n; i++)
        itens[i].ratio = (double) itens[i].valor / itens[i].peso;

    printf("Valor máximo na Mochila Fracionária: %.2f\n", knapsackFracionario(W, itens, n));
    return 0;
}
