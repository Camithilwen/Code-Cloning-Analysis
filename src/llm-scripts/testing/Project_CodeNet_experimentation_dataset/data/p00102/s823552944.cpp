#include <iostream>
#include <cstdio>

using namespace std;

int table[11][11];
int main() {
  int N;
  while (cin >> N) {
    if (N == 0) break;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> table[i][j];
      }
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
      int sum = 0;
      for (int j = 0; j < N; j++) {
        sum += table[i][j];
      }
      table[i][N] = sum;
      total += sum;
    }
    for (int i = 0; i < N; i++) {
      int sum = 0;
      for (int j = 0; j < N; j++) {
        sum += table[j][i];
      }
      table[N][i] = sum;
    }
    table[N][N] = total;
    for (int i = 0; i < N+1; i++) {
      for (int j = 0; j < N+1; j++) {
        printf("%5d", table[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}