#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

// Estrutura para guardar listas de adjacência
// Cada posição terá um vetor dinâmico com os destinos
typedef struct {
    int *adj;
    int tamanho;
    int capacidade;
} Lista;

// Função auxiliar para inserir um destino na lista de adjacência
void inserir(Lista *lista, int destino) {
    // Se não houver espaço, dobra a capacidade
    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2;
        lista->adj = (int *)realloc(lista->adj, lista->capacidade * sizeof(int));
    }
    lista->adj[lista->tamanho++] = destino;
}

int main() {
    int N;
    scanf("%d", &N);

    // Alocação das estruturas
    Lista *grafo = (Lista *)malloc((N+1) * sizeof(Lista));
    int *inDegree = (int *)calloc((N+1), sizeof(int));

    for (int i = 1; i <= N; i++) {]
        grafo[i].tamanho = 0;
        grafo[i].capacidade = 2;  // capacidade inicial pequena
        grafo[i].adj = (int *)malloc(grafo[i].capacidade * sizeof(int));
    }

    // Leitura das N linhas (arestas)
    // Cada linha: a b (b foi indicado por a) => a → b
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        inserir(&grafo[a], b);
        inDegree[b]++;
    }

    // Fila para vértices que têm grau de entrada zero
    // (serão "removidos")
    int *fila = (int *)malloc((N+1) * sizeof(int));
    int inicio = 0, fim = 0;

    // Enfileira vértices que já iniciam com grau de entrada zero
    for (int v = 1; v <= N; v++) {
        if (inDegree[v] == 0) {
            fila[fim++] = v;
        }
    }

    // Processa enquanto houver vértices com grau de entrada zero
    while (inicio < fim) {
        int removido = fila[inicio++];
        // Para cada destino deste removido, decrementa o grau de entrada
        for (int i = 0; i < grafo[removido].tamanho; i++) {
            int destino = grafo[removido].adj[i];
            inDegree[destino]--;
            // Se o destino atingir grau de entrada zero, entra na fila
            if (inDegree[destino] == 0) {
                fila[fim++] = destino;
            }
        }
    }

    // Os vértices restantes com inDegree > 0 formam o subgrupo desejado
    // Precisamos imprimi-los em ordem crescente
    // Uma forma simples: varrer de 1 até N e checar inDegree[v]
    int primeiro = 1;
    for (int v = 1; v <= N; v++) {
        if (inDegree[v] > 0) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", v);
            primeiro = 0;
        }
    }
    printf("\n");

    // Libera memória
    for (int i = 1; i <= N; i++) {
        free(grafo[i].adj);
    }
    free(grafo);
    free(inDegree);
    free(fila);

    return 0;
}