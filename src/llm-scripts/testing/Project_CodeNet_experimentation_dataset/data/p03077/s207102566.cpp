#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  ll tmp = INF;
  rep(i, 5) {
    ll a; cin >> a;
    tmp = min(tmp, a);
  }
  if (n%tmp == 0) cout << n/tmp + 4 << endl;
  else cout << n/tmp + 5 << endl;
}