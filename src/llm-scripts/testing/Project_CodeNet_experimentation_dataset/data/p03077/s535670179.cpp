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
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  ll ans = 0;
  chmax(ans, (n+a-1)/a+4);
  chmax(ans, (n+b-1)/b+4);
  chmax(ans, (n+c-1)/c+4);
  chmax(ans, (n+d-1)/d+4);
  chmax(ans, (n+e-1)/e+4);
  cout << ans << endk;
  return 0;
}
