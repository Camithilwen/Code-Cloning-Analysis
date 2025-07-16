#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
constexpr int MAX = 200001;
lint fact[MAX], finv[MAX], inv[MAX];
void cominit() {
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  FOR(i, 2, MAX){
    fact[i] = fact[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
lint power(lint x, lint n, lint mod) {
  lint ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}
lint ncr(lint n, lint r, lint mod) {
  if(n < 0 || r < 0 || n-r < 0) return 0;
  return fact[n]*finv[r]%mod*finv[n-r]%mod;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint N, M;
  cin >> N >> M;
  cominit();
  vector<lint> fact;
  for(lint i=2; i*i<=M; i++) {
    if(M%i != 0) continue;
    lint ex = 0;
    while(M%i == 0) {
      M /= i;
      ex++;
    }
    fact.push_back(ex);
  }
  if(M > 1) fact.push_back(1);
  lint ans = 1;
  REP(i, fact.size()) ans = ans * ncr(N-1+fact[i], fact[i], MOD) % MOD;
  cout << ans << endl;
  
}