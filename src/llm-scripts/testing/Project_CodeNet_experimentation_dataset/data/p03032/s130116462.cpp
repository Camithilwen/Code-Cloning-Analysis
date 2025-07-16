#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<ll> V(n); rep(i, n) cin >> V[i];
  ll ans = 0;
  rep(i, k+1) rep(j, k+1) {
    int rem = k-(i+j);
    if(rem < 0) continue;
    if(i+j > n) continue;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    rep(ii, i) q.push(V[ii]);
    rep(jj, j) q.push(V[n-1-jj]);
    rep(kk, rem) {
      if(q.empty()) break;
      if(q.top() >= 0) break;
      q.pop();
    }
    ll sum = 0;
    while(!q.empty()) {
      sum += q.top();
      q.pop();
    }
    chmax(ans, sum);
  }
  cout << ans << endk;
  return 0;
}
