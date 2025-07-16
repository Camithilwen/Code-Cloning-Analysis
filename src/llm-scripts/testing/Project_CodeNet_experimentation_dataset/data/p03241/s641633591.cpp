#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, m; cin >> n >> m;
  ll res = 1;
  for (ll i = 1; i*i <= m; i++) {
    if (m%i == 0) {
      if (i*n <= m) res = max(res, i);
      if (m/i != i) {
        if (m/i*n <= m) res = max(res, m/i);
      }
    }
  }
  cout << res << endl;
}