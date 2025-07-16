#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void) {
  int ans = 0, n, min = 101;
  rep(i, 4) {
    scanf("%d", &n);
    ans += n;
    if(n < min) min = n;
  }
  ans -= min;
  min = 101;
  rep(i, 2) {
    scanf("%d", &n);
    ans += n;
    if(n < min) min = n;
  }
  ans -= min;
  printf("%d\n", ans);
  return 0;
}
