#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
long long mod_inv(long long a, long long mod = MOD) {
  a %= mod;
  if (__gcd(a, mod) != 1) return -1;
  long long b = mod, x = 1, y = 0;
  while (b > 0) {
    long long tmp = a / b;
    a -= tmp * b;
    swap(a, b);
    x -= tmp * y;
    swap(x, y);
  }
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

const int MAX = 10000000;
long long fact[MAX + 1], fact_inv[MAX + 1];
void nCk_init(int val = MAX, long long mod = MOD) {
  fact[0] = 1;
  FOR(i, 1, val + 1) fact[i] = fact[i - 1] * i % mod;
  fact_inv[val] = mod_inv(fact[val], mod);
  for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i % mod;
}

long long nCk(int n, int k, long long mod = MOD) {
  if (n < 0 || n < k || k < 0) return 0;
  return fact[n] * fact_inv[k] % mod * fact_inv[n - k] % mod;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  nCk_init();
  int n, m; cin >> n >> m;
  long long ans = 0;
  REP(i, min(n, m) + 1) {
    int gp = 3 * m - i;
    if (gp & 1) continue;
    gp /= 2;
    (ans += nCk(n, i) * nCk(gp + n - 1, n - 1) % MOD) %= MOD;
  }
  long long tmp = 0;
  REP(i, m) (tmp += nCk(i + n - 2, n - 2)) %= MOD;
  (tmp *= n) %= MOD;
  ans -= tmp;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
  return 0;
}
