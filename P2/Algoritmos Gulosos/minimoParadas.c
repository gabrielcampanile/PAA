#include <stdio.h>

int minimoParadas(int postos[], int n, int m, int B) {
    int paradas = 0, posicao = 0, i = 0;

    while (posicao + m < B) {
        int ultimaPosicao = posicao;
        
        // Encontre o posto mais distante dentro do alcance
        while (i < n && postos[i] <= posicao + m) {
            i++;
        }

        // Se não conseguiu avançar, a viagem é impossível
        if (postos[i - 1] == ultimaPosicao) {
            return -1; 
        }

        // Abastece no posto mais distante possível
        posicao = postos[i - 1];
        paradas++;
    }

    return paradas;
}

int main() {
    int postos[] = {100, 200, 300, 400, 500, 600, 700, 800}; // Postos ao longo do caminho
    int n = sizeof(postos) / sizeof(postos[0]);
    int m = 250; // Autonomia do carro (km)
    int B = 900; // Distância total da viagem

    int resultado = minimoParadas(postos, n, m, B);
    
    if (resultado == -1)
        printf("Viagem impossível!\n");
    else
        printf("Mínimo de paradas: %d\n", resultado);

    return 0;
}
