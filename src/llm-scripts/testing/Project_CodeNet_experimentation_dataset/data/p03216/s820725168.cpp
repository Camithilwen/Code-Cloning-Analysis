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
  int n; cin >> n;
  string s; cin >> s;
  int q; cin >> q;
  rep(_, q) {
    int k; cin >> k;
    ll d = 0, m = 0, cnt = 0, ans = 0;
    rep(i, n) {
      if(i >= k) {
        if(s[i-k] == 'D') {
          d--;
          cnt -= m;
        } else if(s[i-k] == 'M') {
          m--;
        }
      }
      if(s[i] == 'D') {
        d++;
      } else if(s[i] == 'M') {
        m++;
        cnt += d;
      } else if(s[i] == 'C') {
        ans += cnt;
      }
    }
    cout << ans << endk;
  }
  return 0;
}
