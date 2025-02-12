#include <stdio.h>

void trocoGuloso(int T, int moedas[], int n) {
    printf("Troco para %d centavos:\n", T);
    for (int i = 0; i < n; i++) {
        if (T >= moedas[i]) {
            int qtd = T / moedas[i];
            T -= qtd * moedas[i];
            printf("%d moeda(s) de %d centavos\n", qtd, moedas[i]);
        }
    }
}

int main() {
    int moedas[] = {25, 10, 5, 1};
    int T = 87;  // Troco desejado
    int n = sizeof(moedas) / sizeof(moedas[0]);

    trocoGuloso(T, moedas, n);
    return 0;
}

