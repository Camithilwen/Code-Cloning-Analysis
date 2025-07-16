#include <stdio.h>
typedef long long ll;

int main(void) {
  ll h, w, n, m;
  scanf("%lld%lld%lld", &h, &w, &n);
  m = h > w ? h : w;
  printf("%lld", (n + m - 1) / m);
  return 0;
}