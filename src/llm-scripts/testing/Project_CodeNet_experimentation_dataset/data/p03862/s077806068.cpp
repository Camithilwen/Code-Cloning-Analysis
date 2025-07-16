#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;

void solve(ll N, ll x, vector<ll> a) {
  ll ans(0);
  if (a[0] > x) {
    ans += a[0] - x;
    a[0] = x;
  }
  FOR(i, 1, N) {
    if (a[i - 1] + a[i] <= x)
      continue;
    ans += a[i - 1] + a[i] - x;
    a[i] = x - a[i - 1];
  }
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, x;
  cin >> N >> x;

  vector<ll> a(N);
  REP(i, N)
    cin >> a[i];

  solve(N, x, move(a));

  return 0;
}
