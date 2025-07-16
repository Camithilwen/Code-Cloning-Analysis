#include <iostream>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int a, b;
  if (m & 1)
    a = m, b = m + 1;
  else
    a = m + 1, b = m;

  for (int i = 1, j = a; i < j; i++, j--)
    printf("%d %d\n", i, j);
  for (int i = 1, j = b; i < j; i++, j--)
    printf("%d %d\n", a + i, a + j);

  return 0;
}