#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
const int MOD = 1000000007;

vector<long long> inv_init(int num) {
  vector<long long> inv(num + 1, 0);
  inv[1] = 1;
  FOR(i, 2, num + 1) inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  return inv;
}

pair<long long, long long> ext_gcd(long long a, long long b) {
  if (b == 0) return {1, 0};
  pair<long long, long long> pr = ext_gcd(b, a % b);
  return {pr.second, pr.first - a / b * pr.second};
}

long long mod_inv(long long a) {
  if (__gcd(a, (long long)MOD) != 1) return 0;
  pair<long long, long long> pr = ext_gcd(a, MOD);
  return (pr.first + MOD) % MOD;
}

const int MAX = 10000000;
long long fact[MAX + 1], fact_inv[MAX + 1];
void nCk_init(int num = MAX) {
  fact[0] = 1;
  FOR(i, 1, MAX + 1) fact[i] = fact[i - 1] * i % MOD;
  fact_inv[MAX] = mod_inv(fact[MAX]);
  for (int i = MAX; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i % MOD;
}

inline long long nCk(int n, int k) {
  if (n < 0 || n < k || k < 0) return 0;
  return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  nCk_init(n);
  vector<long long> inv = inv_init(d);
  // dp[i][j] = 既に i 人グループに含まれており,
  //            各グループの最大人数が j 人
  vector<vector<long long> > dp(n+1, vector<long long>(b+1, 0));
  dp[0][a-1] = 1; // 高々 j 人なので1人もグループ分けされていなくてもよい
  REP(i, n+1) FOR(j, a-1, b) {
    // 既に i 人グループに含まれており, 各グループの最大人数が j 人のとき
    // j+1 人のグループを k (k = 0, c,...,d) グループ作る場合
    // 残りの人々の選び方の総数は
    // C(n-i, j+1) * C(n-i-(j+1), j+1) * ... * C(n-i-(k-1)*(j+1), j+1) / k!
    (dp[i][j+1] += dp[i][j]) %= MOD; // k = 0
    long long tmp = dp[i][j];
    FOR(k, 1, d+1) {
      if (i+k*(j+1) > n) break;
      (tmp *= nCk(n-i-(k-1)*(j+1), j+1) * inv[k] % MOD) %= MOD;
      if (k >= c) (dp[i+k*(j+1)][j+1] += tmp) %= MOD;
    }
  }
  cout << dp[n][b] << '\n';
  return 0;
}
