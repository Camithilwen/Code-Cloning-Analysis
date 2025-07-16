#include <stdio.h>
#include <algorithm>

int m = 0;
int count = 0;
int G[1000000];

void trace(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

void InsertionSort(int A[], int N, int g) {
    for (int i = g; i < N; ++i) {
        int key = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > key) {
            A[j+g] = A[j];
            j = j - g;
            count++;
        }
        A[j + g] = key;
    }
}

void ShellSort(int A[], int N) {
    int g = 0;
    while(true) {
        g = 3 * g + 1;
        if (g > N) { break; }
        G[m] = g;
        ++m;
    }
    for (int i = m - 1; i >= 0; --i) {
        InsertionSort(A, N, G[i]);
    }

}

int main() {
    int N;
    int A[1000000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    ShellSort(A, N);

    printf("%d\n", m);
    for (int i = m - 1; i >= 0; --i) {
        printf("%d", G[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    printf("%d\n", count);
    for (int i = 0; i < N; i++) {
        printf("%d\n", A[i]);
    }
    return 0;
}