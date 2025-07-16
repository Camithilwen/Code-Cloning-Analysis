#include<stdio.h>

int insertionSort(int A[], int n, int g) {
  int cnt = 0;
  for (int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while ( j >= 0 && v < A[j]) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }

  return cnt;
}

void shellSort(int A[], int n) {
  int im, m = 1, v = 1, G[100], sum = 0;
  for ( im = 0; v <= n; im++ ) {
    G[im] = v;
    m *= 3;
    v += m;
  }

  printf("%d\n", im);
  for ( int i = im - 1; i >= 0; i-- ) {
    if ( i != (im - 1) ) printf(" ");
    printf("%d", G[i]);
    sum += insertionSort(A, n, G[i]);
  }

  printf("\n%d\n", sum);
  for ( int i = 0; i < n; i++ ) {
    printf("%d\n", A[i]);
  }
}

int main() {
  int n, A[1000000];
  scanf("%d", &n);

  for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);

  shellSort(A, n);

  return 0;
}

