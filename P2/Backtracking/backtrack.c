#include <stdio.h>

#define MAXCANDIDATES 2
#define NMAX 100

typedef int bool;
#define TRUE 1
#define FALSE 0

bool finished = FALSE; /* encontrado todas as soluções? */

void process_solution(int a[], int k) {
    int i; /* contador */
    printf("{");
    for (i = 1; i <= k; i++)
        if (a[i] == TRUE)
            printf(" %d", i);
    printf(" }\n");
}

bool is_a_solution(int a[], int k, int n) {
    return (k == n); /* solução completa quando k == n */
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
    /* Sempre teremos duas opções para cada posição:
       TRUE  (o elemento está presente no subconjunto)
       FALSE (o elemento não está presente no subconjunto) */
    c[0] = TRUE;
    c[1] = FALSE;
    *ncandidates = 2;
}

void make_move(int a[], int k, int n) {
    /* Nesta implementação para geração de subconjuntos,
       não há nenhum estado adicional para modificar.
       A função está presente para fins ilustrativos. */
}

void unmake_move(int a[], int k, int n) {
    /* Reverte qualquer modificação realizada em make_move.
       Aqui, nada precisa ser feito. */
}

void backtrack(int a[], int k, int n) {
    int c[MAXCANDIDATES]; /* candidatos para a próxima posição */
    int ncandidates;      /* quantidade de candidatos */
    int i;              /* contador */
    
    if (is_a_solution(a, k, n))
        process_solution(a, k);
    else {
        k = k + 1;
        construct_candidates(a, k, n, c, &ncandidates);
        for (i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            make_move(a, k, n);
            backtrack(a, k, n);
            unmake_move(a, k, n);
            if (finished)
                return; /* termina cedo se todas as soluções já foram encontradas */
        }
    }
}

void generate_subsets(int n) {
    int a[NMAX]; /* vetor de solução */
    backtrack(a, 0, n);
}

int main() {
    int n;
    printf("Digite o número de elementos no conjunto: ");
    scanf("%d", &n);
    generate_subsets(n);
    return 0;
}
