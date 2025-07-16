#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, Q;
  string S;
  cin >> N >> S >> Q;
  rep(q, Q) {
    int k;
    cin >> k;
    ll cntD = 0, cntM = 0;
    ll cnt = 0;
    ll ans = 0;
    rep(i, N) {
      if(S[i] == 'D') {
        cntD++;
      } else if(S[i] == 'M') {
        cntM++;
        cnt += cntD;
      } else if(S[i] == 'C') {
        ans += cnt;
      }

      if(i >= k-1) {
        if(S[i-k+1] == 'D') {
          cntD--;
          cnt -= cntM;
        } else if(S[i-k+1] == 'M') {
          cntM--;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
