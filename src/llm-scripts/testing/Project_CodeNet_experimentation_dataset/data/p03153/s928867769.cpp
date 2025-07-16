#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
int n; ll k, ans, a[maxn], lef[maxn], rig[maxn];

int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i), ans += a[i];
  }
  ans += (n - 1) * k;
  lef[1] = a[1];
  for (int i = 2; i <= n; i++) {
    lef[i] = min(a[i], lef[i - 1] + k);
  }
  rig[n] = a[n];
  for (int i = n - 1; i; i--) {
    rig[i] = min(a[i], rig[i + 1] + k);
  }
  for (int i = 2; i < n; i++) {
    ans += min(lef[i], rig[i]);
  }
  printf("%lld", ans);
  return 0;
}