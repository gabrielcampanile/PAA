#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 10  // Tamanho do tabuleiro (8x8)

// Função que verifica se é seguro posicionar uma rainha na coluna 'col' e linha 'row'
// em relação às rainhas já posicionadas nas colunas anteriores.
bool is_safe(int board[], int col, int row) {
    int i;
    for (i = 0; i < col; i++) {
        // Verifica se já existe uma rainha na mesma linha
        if (board[i] == row)
            return false;
        // Verifica se já existe uma rainha na mesma diagonal
        // A distância absoluta entre linhas deve ser diferente da distância entre colunas
        if (abs(board[i] - row) == abs(i - col))
            return false;
    }
    return true;
}

// Função recursiva de backtracking que tenta posicionar rainhas coluna a coluna.
// Se for possível posicionar todas as rainhas (col == N), retorna true.
bool solve(int board[], int col) {
    int row;
    if (col >= N)
        return true;  // todas as rainhas foram posicionadas com sucesso

    // Tenta colocar a rainha em cada linha da coluna 'col'
    for (row = 0; row < N; row++) {
        if (is_safe(board, col, row)) {
            board[col] = row; // coloca a rainha na posição (col, row)
            // Tenta posicionar as rainhas nas colunas seguintes
            if (solve(board, col + 1))
                return true;
            // Se não for possível, volta atrás (backtracking) e tenta outra linha
        }
    }
    // Se nenhuma linha foi adequada para esta coluna, retorna false
    return false;
}

// Função que imprime o tabuleiro com a solução encontrada.
// Uma posição com 'Q' indica a presença de uma rainha; '.' indica casa vazia.
void print_board(int board[]) {
    int i, j;
    for (i = 0; i < N; i++) {  // para cada linha
        for (j = 0; j < N; j++) {  // para cada coluna
            if (board[j] == i)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    int board[N];
    
    // Inicializa o vetor board (opcional)
    for (int i = 0; i < N; i++) {
        board[i] = -1;
    }
    
    if (solve(board, 0)) {
        printf("Solução encontrada:\n");
        print_board(board);
    } else {
        printf("Nenhuma solução encontrada.\n");
    }
    
    return 0;
}
