#include <stdio.h>

// Função para ordenar os tamanhos das caixas em ordem decrescente
void sortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m;  // n: demanda do cliente, m: número de tamanhos de caixas disponíveis
    scanf("%d %d", &n, &m);

    int caixas[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &caixas[i]);
    }

    // Ordena as caixas em ordem decrescente
    sortDesc(caixas, m);

    int demanda = n;
    int totalCaixas = 0;

    for (int i = 0; i < m && demanda > 0; i++) {
        totalCaixas += demanda / caixas[i];
        demanda %= caixas[i];
    }

    if (demanda == 0) {
        printf("%d\n", totalCaixas);
    } else {
        printf("-1\n");  // Não foi possível atender exatamente a demanda
    }

    return 0;
}
