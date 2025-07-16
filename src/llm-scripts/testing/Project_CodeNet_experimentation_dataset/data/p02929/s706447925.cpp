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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  string S;
  cin >> N >> S;
  int cnt = 0;
  ll ans = 1;
  rep(i, 2*N) {
    if(S[i] == 'B') {
      if(cnt%2) {
        if(cnt == 0) {
          ans = 0;
          break;
        }
        (ans *= cnt) %= mod;
        cnt--;
      } else {
        ans *= 1;
        cnt++;
      }
    } else {
      if(cnt%2) {
        ans *= 1;
        cnt++;
      } else {
        if(cnt == 0) {
          ans = 0;
          break;
        }
        (ans *= cnt) %= mod;
        cnt--;
      }
    }
  }
  function<ll(ll)> fact = [&](ll n) {
    if(n == 0) return 1LL;
    else return (n * fact(n-1)) % mod;
  };
  if(cnt) cout << 0 << endl;
  else cout << (ans * fact(N)) % mod << endl;
  return 0;
}
