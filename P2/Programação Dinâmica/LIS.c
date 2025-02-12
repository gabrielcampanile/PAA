#include <stdio.h>

#define MAX_N 1000

int lis_dp(int arr[], int n) {
    int dp[MAX_N];
    int maxLIS = 1;

    // Inicializa cada posição com 1, pois LIS mínima é o próprio elemento
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    // Preenchendo a tabela dp
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (dp[i] > maxLIS)
                    maxLIS = dp[i];
            }
        }
    }
    return maxLIS;
}

int main() {
    int arr[] = {-7, 10, 9, 2, 3, 8, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("LIS (O(n^2)): %d\n", lis_dp(arr, n));
    return 0;
}
