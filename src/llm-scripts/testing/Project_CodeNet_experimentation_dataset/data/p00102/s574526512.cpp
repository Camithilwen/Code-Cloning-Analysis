#include <cstdio>
#include <cstring>

#define repeat(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int table[11][11];

int main() {
  for (;;) {
    int n;
    scanf("%i", &n);
    if (!n) return 0;
    memset(table, 0, sizeof table);
    repeat(i, n) {
      repeat(j, n) {
        scanf("%i", &table[i][j]);
        table[i][n] += table[i][j];
        table[n][j] += table[i][j];
        printf("%5i", table[i][j]);
      }
      printf("%5i\n", table[i][n]);
    }
    repeat(i, n)
      table[n][n] += table[n][i];
    repeat (i, n+1)
      printf("%5i", table[n][i]);
    puts("");
  }
}