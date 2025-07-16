#include <stdio.h>

int main() {
  int h1, h2, m1, m2, k, ans;
  scanf("%d%d%d%d%d", &h1, &m1, &h2, &m2, &k);
  ans = (h2 - h1) * 60 + (m2 - m1) - k;
  printf("%d\n", ans);
}