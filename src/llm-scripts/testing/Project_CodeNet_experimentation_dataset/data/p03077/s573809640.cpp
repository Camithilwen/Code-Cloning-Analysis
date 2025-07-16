#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n; cin >> n;
  vector<ll> t(5);
  rep(i,5) cin >> t[i];
  ll bn = *min_element(t.begin(),t.end());
  ll ans = 5;
  if (n>bn) {
    ans = n/bn + 4;
    if (n > (n/bn) * bn) ans++;
  }
  cout << ans << endl;
  return 0;
}