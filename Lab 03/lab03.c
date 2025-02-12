#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX 15
#define TAM_FILA 10000
#define LIMITE 10000

typedef struct {
    int valores[TAM_MAX];
    int tamanho;
} Sequencia;

void copia_sequencia(Sequencia *destino, Sequencia *origem) {
    destino->tamanho = origem->tamanho;
    memcpy(destino->valores, origem->valores, sizeof(int) * origem->tamanho);
}

Sequencia dobra_sequencia(Sequencia *seq, int indice) {
    Sequencia nova;
    nova.tamanho = 0;

    int esq = indice - 1;  // Parte esquerda
    int dir = indice;      // Parte direita

    // Soma os lados esquerdo e direito
    while (esq >= 0 && dir < seq->tamanho) {
        nova.valores[nova.tamanho++] = seq->valores[esq] + seq->valores[dir];
        esq--;
        dir++;
    }

    // Copia o restante da esquerda
    while (esq >= 0) {
        nova.valores[nova.tamanho++] = seq->valores[esq--];
    }

    // Copia o restante da direita
    while (dir < seq->tamanho) {
        nova.valores[nova.tamanho++] = seq->valores[dir++];
    }

    // Reverte a sequência final
    for (int i = 0; i < nova.tamanho / 2; i++) {
        int temp = nova.valores[i];
        nova.valores[i] = nova.valores[nova.tamanho - i - 1];
        nova.valores[nova.tamanho - i - 1] = temp;
    }

    return nova;
}

bool sequencias_iguais(Sequencia *a, Sequencia *b) {
    if (a->tamanho != b->tamanho) return false;
    for (int i = 0; i < a->tamanho; i++) {
        if (a->valores[i] != b->valores[i]) return false;
    }
    return true;
}

bool ja_visitada(Sequencia *seq, Sequencia *visitadas, int qtd_visitadas) {
    for (int i = 0; i < qtd_visitadas; i++) {
        if (sequencias_iguais(seq, &visitadas[i])) {
            return true;
        }
    }
    return false;
}

bool verifica_casos_especiais(Sequencia *origem, Sequencia *alvo) {
    // Caso especial: sequências já iguais
    if (sequencias_iguais(origem, alvo)) return true;

    // Caso especial: inversão simples
    Sequencia invertida;
    invertida.tamanho = origem->tamanho;
    for (int i = 0; i < origem->tamanho; i++) {
        invertida.valores[i] = origem->valores[origem->tamanho - i - 1];
    }
    if (sequencias_iguais(&invertida, alvo)) return true;

    return false;
}

bool consegue_gerar(Sequencia *origem, Sequencia *alvo) {
    // Verifica casos especiais primeiro
    if (verifica_casos_especiais(origem, alvo)) return true;

    Sequencia fila[TAM_FILA];
    Sequencia visitadas[TAM_FILA];
    int inicio = 0, fim = 0, total_visitadas = 0;

    // Adiciona a sequência inicial
    copia_sequencia(&fila[fim++], origem);
    copia_sequencia(&visitadas[total_visitadas++], origem);

    while (inicio < fim && total_visitadas < LIMITE) {
        Sequencia atual;
        copia_sequencia(&atual, &fila[inicio++]);

        // Verifica se chegou no alvo
        if (sequencias_iguais(&atual, alvo)) return true;

        // Tenta dobrar a sequência em todos os índices válidos
        for (int i = 1; i < atual.tamanho; i++) {
            Sequencia nova = dobra_sequencia(&atual, i);

            if (!ja_visitada(&nova, visitadas, total_visitadas)) {
                if (sequencias_iguais(&nova, alvo)) return true;

                // Adiciona a nova sequência na fila e nas visitadas
                copia_sequencia(&fila[fim++], &nova);
                copia_sequencia(&visitadas[total_visitadas++], &nova);
            }
        }
    }

    return false;
}

int main() {
    Sequencia origem, alvo;
    int N, M;

    scanf("%d", &N);
    origem.tamanho = N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &origem.valores[i]);
    }

    scanf("%d", &M);
    alvo.tamanho = M;
    for (int i = 0; i < M; i++) {
        scanf("%d", &alvo.valores[i]);
    }

    printf("%s\n", consegue_gerar(&origem, &alvo) ? "S" : "N");

    return 0;
}
