#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const int S = N * N;
const int mod = 998244353;

void add(int &x,int y) {
  x += y;
  if (x >= mod) x -= mod;
}

void sub(int &x,int y) {
  x -= y;
  if (x < 0) x += mod;
}

int mul(int x,int y) {
  return (long long) x * y % mod;
}

int a[N];
int f[S], g[S];
int nf[S], ng[S];

int main() {
  int n;
  scanf("%d", &n);
  f[0] = 1;
  g[0] = 1;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j <= sum; ++j) {
      add(nf[j], f[j]);
      add(nf[j + x], f[j]);
      add(ng[j], mul(g[j], 2));
      add(ng[j + x], g[j]);
    }
    sum += x;
    for (int j = 0; j <= sum; ++j) {
      f[j] = nf[j], nf[j] = 0;
      g[j] = ng[j], ng[j] = 0;
    }
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) ans = mul(ans, 3);
  for (int i = 0; i <= sum; ++i) if (i + i >= sum) {
    sub(ans, mul(g[i], 3));
  }
  if (sum % 2 == 0) add(ans, mul(f[sum / 2], 3));
  printf("%d\n", ans);
  return 0;
}
