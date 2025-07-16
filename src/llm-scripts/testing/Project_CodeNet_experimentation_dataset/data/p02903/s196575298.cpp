#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, h, w, a, b;
  scanf("%lld%lld%lld%lld", &h, &w, &a, &b);
  for(i = 0; i < h; ++i) {
    for(j = 0; j < w; ++j) printf("%d", (i < b) ^ (j < a));
    printf("\n");
  }
  return 0;
}