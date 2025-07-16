#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll m; cin >> n >> m;
  vector<ll> A(n), sum(n+1);
  rep(i, n) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
  }
  map<ll, ll> rem;
  rep(i, n+1) rem[sum[i]%m]++;
  ll ans = 0;
  for(auto ele: rem) {
    ans += ele.second * (ele.second-1) / 2;
  }
  cout << ans << "\n";
  return 0;
}
