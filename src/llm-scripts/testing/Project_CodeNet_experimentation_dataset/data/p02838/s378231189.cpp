#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

constexpr ll MOD = 1000000007;

int main() {
  ll n;
  cin >> n;
  ll a;

  vector<ll> one(60);
  rep(i, 0, n) {
    cin >> a;
    rep(j, 0, 60) if (a >> j & 1) one[j]++;
  }

  ll ans = 0;
  rep(i, 0, 60) ans =
    (ans + (1ll << i) % MOD * one[i] % MOD * (n - one[i]) % MOD) % MOD;

  cout << ans << endl;
  return 0;
}
