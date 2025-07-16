#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  REP(i, n) cin >> v[i];
  ll ans = -INF;
  ll r = min(n, k);
  FORe(a, 0, r){
    for(ll b = 0; a+b <= r; b++){
      vector<ll> p;
      ll now = 0;
      REP(i, a) p.emplace_back(v[i]), now += v[i];
      REP(i, b) p.emplace_back(v[n-i-1]), now += v[n-i-1];
      sort(ALL(p));
      ll c = min(k-a-b, (ll)p.size());
      REP(i, c){
        if(p[i] < 0) now -= p[i];
      }
      chmax(ans, now);
    }
  }
  cout << ans << endl;
  return 0;
}