#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

typedef struct {
    int *adj;
    int tamanho;
    int capacidade;
} Lista;

void inserir(Lista *lista, int destino) {
    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2;
        lista->adj = (int *)realloc(lista->adj, lista->capacidade * sizeof(int));
    }
    lista->adj[lista->tamanho++] = destino;
}

int main() {
    int N;
    scanf("%d", &N);

    Lista *grafo = (Lista *)malloc((N+1) * sizeof(Lista));
    int *inDegree = (int *)calloc((N+1), sizeof(int));

    for (int i = 1; i <= N; i++) {
        grafo[i].tamanho = 0;
        grafo[i].capacidade = 2;
        grafo[i].adj = (int *)malloc(grafo[i].capacidade * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        inserir(&grafo[a], b);
        inDegree[b]++;
    }

    int *fila = (int *)malloc((N+1) * sizeof(int));
    int inicio = 0, fim = 0;

    for (int v = 1; v <= N; v++) {
        if (inDegree[v] == 0) {
            fila[fim++] = v;
        }
    }

    while (inicio < fim) {
        int removido = fila[inicio++];
        for (int i = 0; i < grafo[removido].tamanho; i++) {
            int destino = grafo[removido].adj[i];
            inDegree[destino]--;
            if (inDegree[destino] == 0) {
                fila[fim++] = destino;
            }
        }
    }

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

    for (int i = 1; i <= N; i++) {
        free(grafo[i].adj);
    }
    free(grafo);
    free(inDegree);
    free(fila);

    return 0;
}
