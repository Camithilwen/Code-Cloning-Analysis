#include <cstdio>

int matrix[12][12];
int n;

int main() {
  while(scanf("%d", &n) != EOF, n) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
	scanf("%d", &matrix[i][j]);
      }
    }

    // output
    for (int i=0; i<n; i++) {
      int sum = 0;
      for (int j=0; j<n; j++) {
	sum += matrix[i][j];
	printf("%5d", matrix[i][j]);
      }
      matrix[i][n] = sum; 
      printf("%5d\n", sum);
    }

    for (int j=0; j<=n; j++) {
      int sum = 0;
      for (int k=0; k<n; k++) {
	sum += matrix[k][j];
      }
      printf("%5d", sum);
    }
    printf("\n");
  }
}