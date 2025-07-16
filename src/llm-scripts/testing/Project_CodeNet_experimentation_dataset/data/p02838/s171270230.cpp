#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

constexpr const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0, two_factor = 1;
  rep(i, 60) {
    ll even = 0;
    rep(j, n) if ((a[j] >> i) & 1) even++;
    ll add = (even * (n - even)) % mod * two_factor % mod;
    ans = (ans + add) % mod;
    two_factor = (two_factor * 2) % mod;
  }
  cout << ans << endl;
  return 0;
}
