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
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  ll ans = 0;
  for(int i=0; i<=k; i++) { // push
    int j = k-i; // pop
    if(j >= n) {
      priority_queue<ll, vector<ll>, greater<ll>> q;
      rep(l, n) q.push(v[l]);
      rep(l, i) {
        if(q.empty()) break;
        if(q.top() >= 0) break;
        q.pop();
      }
      ll tmp = 0;
      while(!q.empty()) {
        tmp += q.top();
        q.pop();
      }
      chmax(ans, tmp);
    } else {
      for(int l=0; l<=j; l++) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        rep(m, l) q.push(v[m]);
        rep(m, j-l) q.push(v[n-1-m]);
        rep(m, i) {
          if(q.empty()) break;
          if(q.top() >= 0) break;
          q.pop();
        }
        ll tmp = 0;
        while(!q.empty()) {
          tmp += q.top();
          q.pop();
        }
        chmax(ans, tmp);
      }
    }
  }
  cout << ans << endk;
  return 0;
}
