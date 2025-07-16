#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
  const ll M = 998244353;
  ll N, ans = 1;
  cin >> N;
  vector<ll> d;
  vector<ll> cnt(N, 0);
  for (ll i = 0; i < N; i++) {
    ll x;
    cin >> x;
    if (i == 0) {
      if (x != 0) ans = 0;
    } else {
      d.push_back(x);
    }
    cnt[x]++;
  }
  for (auto x : d) {
    if (x > 0) ans *= cnt[x-1];
    else ans = 0;
    ans %= M;
  }
  cout << ans << endl;
  return 0;
}
