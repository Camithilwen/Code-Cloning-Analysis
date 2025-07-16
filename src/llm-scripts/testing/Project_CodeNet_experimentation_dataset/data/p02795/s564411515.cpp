#include <stdio.h>

int main() {
  int rows, columns, n, tempR = 1, tempC = 1;
  scanf("%d %d %d", &rows, &columns, &n);

  int i = 1, j = 1;
  while(tempR < n && i <= rows) {
    tempR = i * columns;
    i++;
  }
  while(tempC < n && j <= columns) {
    tempC = j * rows;
    j++;
  }

  if(i == 1 && j == 1) printf ("1");
  else if(i < j) printf("%d", i - 1);
  else printf("%d", j - 1);
  return 0;
}