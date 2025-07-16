#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#define maxn 2010
#define maxv 4000010
#define ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define IL inline
#define ss system
using namespace std;

int n, k;
ll f[maxn][maxn], fac[maxv], ifac[maxv];
const ll p = 1e9 + 7;
template <class T> void read (T &x) {
  char ch = x = 0;
  bool fl = false;
  while (!isdigit(ch))
    fl |= ch == '-', ch = getchar();
  while (isdigit(ch))
    x = x * 10 + ch - '0', ch = getchar();
  x = fl ? -x : x;
}
ll pw(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1)
      ret = ret * a % p;
    a = a * a % p, b >>= 1;
  }
  return ret;
}
ll C(int a, int b) {
  return a < b || b < 0 ? 0 : fac[a] * ifac[b] % p * ifac[a - b] % p;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < maxv; i++) {
    fac[i] = fac[i - 1] * i % p;
  }
  ifac[maxv - 1] = pw(fac[maxv - 1], p - 2);
  for (int i = maxv - 2; ~i; i--) {
    ifac[i] = ifac[i + 1] * (i + 1) % p;
  }
}
int main() {
  read(n), read(k), init(), f[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = !i; j <= i; j++) {
      if (i)
        f[i][j] = f[i - 1][j];
      f[i][j] = (f[i][j] + f[i][j - 1] * (n - j + 1) % p * C(n - i + (n - j + 1) * (k - 1) - 1, k - 2)) % p;
    }
  }
  printf("%d\n", f[n][n * (k > 1)]);
  return 0;
}