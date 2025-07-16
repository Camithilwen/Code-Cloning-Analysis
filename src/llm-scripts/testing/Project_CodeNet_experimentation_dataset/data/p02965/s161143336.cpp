#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> pi;

#define fi first
#define se second

int read() {
  int res = 0, w = 1; char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') c = getchar(), w = -1;
  while (isdigit(c)) res = (res << 1) + (res << 3) + c - '0', c = getchar();
  return res * w;
}

const int Mod = 998244353;

int add(int a, int b) { return (a += b) >= Mod ? a - Mod : a; }

int sub(int a, int b) { return (a -= b) < 0 ? a + Mod : a; }

int mul(int a, int b) { return 1ll * a * b % Mod; }

int fast_pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) res = mul(res, a);
  return res;
}

const int N = 3e6 + 10;

int fac[N], inv[N];

void init(int n = N - 1) {
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = fast_pow(fac[n], Mod - 2);
  for (int i = n - 1; i >= 1; i--) inv[i] = mul(inv[i + 1], i + 1);
}

int C(int a, int b) { return a >= b ? mul(fac[a], mul(inv[b], inv[a - b])) : 0;}

int main() {
#ifdef dream_maker
//  freopen("tst.in", "r", stdin);
#else
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
#endif
  init();
  int n = read(), m = read(), ans = 0;
  for (int i = 0; i <= m; i++) if ((3 * m - i) & 1 ^ 1) {
    ans = add(ans, mul(C(n, i), C(((3 * m - i) >> 1) + n - 1, n - 1)));
  }
  ans = sub(ans, mul(n, C(m - 1 + n - 1, n - 1)));
  cout << ans << endl;
  return 0;
}
