#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll n, t;
  cin >> n >> t;
  vector<ll> tv(n);
  rep(i, n) {
    cin >> tv[i];
  }

  ll ans = t;
  for (int i = 1; i < n; ++i) {
    ans += t;
    if (t > tv[i] - tv[i - 1]) ans = ans - t + tv[i] - tv[i - 1];
  }

  cout << ans << endl;
  
  return 0;
}