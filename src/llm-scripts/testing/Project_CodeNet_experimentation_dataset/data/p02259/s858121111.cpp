#include <cstdio>

void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i != N-1) {
            printf("%d ", A[i]);
        } else {
            printf("%d", A[i]);
        }
    }
    printf("\n");
}

void bubbleSort(int A[], int N) {
    bool unsorted = 1;
    int i = 0;
    int counter = 0;
    while (unsorted) {
        unsorted = 0;
        for (int j = N-1; j >= i; j--) {
            if (A[j] < A[j-1]) {
                int tmp = A[j];
                A[j]    = A[j-1];
                A[j-1]  = tmp;
                unsorted = 1;
                counter++;
            }
        }
        i++;
    }
    printArray(A, N);
    printf("%d\n", counter);
}

int main() {
    int N;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        A[i] = input;
    }
    bubbleSort(A, N);
}