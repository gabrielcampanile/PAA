#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VISITED 50000

// Estrutura para representar uma sequência.
// Usamos um array de tamanho 20 – suficiente, pois N <= 15.
typedef struct {
    int len;
    long long v[20];
} Seq;

Seq target; // Sequência alvo (global)

// Vetor global para armazenar estados visitados (representados como string)
// e uma variável para contar quantos estados já foram armazenados.
char *visited[MAX_VISITED];
int visited_count = 0;

// Função que converte uma sequência em uma string (chave) para identificar o estado.
// Exemplo: para a sequência {3,7,1,2,8}, a string gerada será "3,7,1,2,8,"
void seqToString(const Seq *seq, char *buffer) {
    buffer[0] = '\0';
    char temp[32];
    for (int i = 0; i < seq->len; i++) {
        sprintf(temp, "%lld,", seq->v[i]);
        strcat(buffer, temp);
    }
}

// Verifica se a chave já foi armazenada entre os estados visitados.
int isVisited(const char *key) {
    for (int i = 0; i < visited_count; i++) {
        if (strcmp(visited[i], key) == 0)
            return 1;
    }
    return 0;
}

// Armazena a chave de um estado no vetor de visitados.
void addVisited(const char *key) {
    if (visited_count < MAX_VISITED) {
        visited[visited_count++] = strdup(key);
    }
}

// Compara duas sequências; retorna 1 se forem iguais e 0 caso contrário.
int equalsSeq(const Seq *a, const Seq *b) {
    if(a->len != b->len)
        return 0;
    for (int i = 0; i < a->len; i++) {
        if(a->v[i] != b->v[i])
            return 0;
    }
    return 1;
}

// Função que implementa a operação de dobra.
// Dada a sequência s e um índice pos (0 ≤ pos ≤ s->len):
// - Se pos==0 ou pos==s->len, a nova sequência é simplesmente a inversa de s.
// - Caso contrário, dividimos s em duas partes:
//      L = s[0 ... pos-1] e R = s[pos ... s->len-1].
//   Em seguida, invertemos R (obtendo R_rev) e “alinhamos” as partes para somar os elementos sobrepostos.
//   Se R_rev tiver mais elementos que L, os elementos “extras” de R_rev viram os primeiros elementos da nova sequência.
//   Caso contrário, os elementos que não se sobrepõem em L são mantidos no início.
Seq foldSequence(const Seq *s, int pos) {
    Seq newSeq;
    int n = s->len;
    if (pos == 0 || pos == n) {
        // Dobra igual a inverter a sequência.
        newSeq.len = n;
        for (int i = 0; i < n; i++) {
            newSeq.v[i] = s->v[n - 1 - i];
        }
        return newSeq;
    }
    // Divide a sequência em L (prefixo) e R (sufixo).
    int L_len = pos;
    int R_len = n - pos;
    // Cria R_rev, que é R invertido.
    long long R_rev[20];
    for (int i = 0; i < R_len; i++) {
        R_rev[i] = s->v[n - 1 - i];
    }
    // Se R_rev tem mais elementos que L, os primeiros (R_len - L_len) elementos não se sobrepõem.
    if (R_len > L_len) {
        int extra = R_len - L_len;
        newSeq.len = R_len;
        int index = 0;
        for (int i = 0; i < extra; i++) {
            newSeq.v[index++] = R_rev[i];
        }
        for (int i = 0; i < L_len; i++) {
            newSeq.v[index++] = s->v[i] + R_rev[extra + i];
        }
    } else { // Se R_len <= L_len, os elementos “extras” vêm de L.
        int extra = L_len - R_len;
        newSeq.len = L_len;
        int index = 0;
        for (int i = 0; i < extra; i++) {
            newSeq.v[index++] = s->v[i];
        }
        for (int i = 0; i < R_len; i++) {
            newSeq.v[index++] = s->v[extra + i] + R_rev[i];
        }
    }
    return newSeq;
}

// Função de backtracking: retorna 1 se for possível obter a sequência alvo a partir de s.
int solve(Seq s) {
    // Se o tamanho da sequência atual for menor que o da sequência alvo,
    // não é possível “crescer” a sequência; retorna 0.
    if (s.len < target.len)
        return 0;
    
    // Se os tamanhos são iguais, verifica se s é igual à sequência alvo.
    if (s.len == target.len) {
        if (equalsSeq(&s, &target))
            return 1;
    }
    
    // Gera uma chave para o estado atual.
    char key[512];
    seqToString(&s, key);
    if (isVisited(key))
        return 0;
    addVisited(key);
    
    // Para cada posição de dobra possível (de 0 até s.len)
    // gera uma nova sequência e chama recursivamente.
    for (int pos = 0; pos <= s.len; pos++) {
        Seq newSeq = foldSequence(&s, pos);
        if (solve(newSeq))
            return 1;
    }
    return 0;
}

int main(){
    int N, M;
    Seq original;
    
    // Leitura da sequência original
    scanf("%d", &N);
    original.len = N;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &original.v[i]);
    }
    
    // Leitura da sequência a ser verificada (alvo)
    scanf("%d", &M);
    target.len = M;
    for (int i = 0; i < M; i++) {
        scanf("%lld", &target.v[i]);
    }
    
    // Reinicia o conjunto de estados visitados.
    visited_count = 0;
    
    // Se for possível obter a sequência alvo a partir da original, imprime "S"; caso contrário, "N".
    if (solve(original))
        printf("S\n");
    else
        printf("N\n");
    
    // Libera a memória alocada para as chaves armazenadas.
    for (int i = 0; i < visited_count; i++) {
        free(visited[i]);
    }
    
    return 0;
}
