#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int B = 100000007;
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
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
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vector<lint> a(N);
  REP(i, N) cin >> a[i];
  vector<lint> b(N);
  REP(i, N) cin >> b[i];
  vector<lint> pa(N);
  vector<lint> pb(N);
  REP(i, N) {
    pa[i] = a[i] ^ a[(i+1)%N];
    pb[i] = b[i] ^ b[(i+1)%N];
  }
  lint hash = 0;
  lint target = 0;
  REP(i, N) {
    hash = (hash + pa[i]*power(B, i, MOD)) % MOD;
    target = (target + pb[i]*power(B, i, MOD)) % MOD;
  }
  vector<pair<lint, lint>> ans;
  REP(i, N) {
    //cout << hash << " " << target << endl;
    if(hash == target) {
      lint x = b[0] ^ a[i];
      ans.push_back(make_pair(i, x));
    }
    hash = hash * power(B, MOD-2, MOD) % MOD;
    hash = (hash - pa[i]*power(B, MOD-2, MOD) % MOD + pa[i]*power(B, N-1, MOD) + MOD) % MOD;
  }
  sort(ans.begin(), ans.end(), [](auto const &a, auto const &b) { return a.first < b.first; });
  REP(i, ans.size()) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }

}