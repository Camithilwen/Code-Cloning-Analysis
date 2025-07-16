#include <stdio.h>

int main () {
    int N, K, A = 1;
    scanf("%d %d", &N, &K);
    
    for (int i = 1; i <= N; i++) {
        if (A * 2 < A + K) {
            A *= 2;
        }
        else {
            A += K;
        }
    }
    printf("%d", A);
}