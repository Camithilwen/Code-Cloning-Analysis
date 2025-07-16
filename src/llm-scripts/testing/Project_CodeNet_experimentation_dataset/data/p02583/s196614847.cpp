#include <bits/stdc++.h>
#define reg register
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN = 110;
int n;
ll a[MAXN];
void work() {
  scanf("%d", &n);
  for(reg int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  int ans = 0;
  for(reg int i = 1; i <= n; ++i) {
    for(reg int j = i + 1; j <= n; ++j) {
      for(reg int k = j + 1; k <= n; ++k) {
        if(a[i] != a[j] && a[j] != a[k] && a[i] != a[k]) {
          if(a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i]) ++ans;
        }
      }
    }
  }
  printf("%d\n", ans);
}
signed main() {
  int _ = 1;
  // scanf("%d", &_);
  while(_--) {
    work();
  }
  return 0;
}
