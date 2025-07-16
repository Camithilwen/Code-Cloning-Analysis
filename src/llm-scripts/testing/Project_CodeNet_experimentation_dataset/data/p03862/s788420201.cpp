#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;

  ll ans = 0;
  for (ll i = 1; i< n; ++i) {
    ll vsum = vec[i] + vec[i-1];
    if (vsum <= x)
      continue;
    else if (vsum - x <= vec[i])
      vec[i] -= vsum - x;
    else
      vec[i] = 0;
    ans += vsum - x;
  }

  cout << ans << endl;
}