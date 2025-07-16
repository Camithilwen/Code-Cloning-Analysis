#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using vl = vector<ll>;

int main() {
  ll n;
  cin >> n;
  vl x(n);
  rep(i, n) cin >> x[i];
  ll l, q;
  cin >> l >> q;
  vector<vl> r(20, vl(n));
  rep(i, n) r[0][i] = upper_bound(all(x), x[i] + l) - x.begin() - 1;
  rep(k, 19) rep(i, n) r[k + 1][i] = r[k][r[k][i]];
  rep(_, q) {
    ll a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    a--;
    b--;
    ll ans = 1;
    for(ll k = 19; k >= 0; k--)
      if(r[k][a] < b) {
        a = r[k][a];
        ans += 1 << k;
      }
    cout << ans << '\n';
  }
}