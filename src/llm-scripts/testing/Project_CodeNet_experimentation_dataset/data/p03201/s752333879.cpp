#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  ll ans = 0;
  vector<bool> used(N, false);
  for (ll i = N - 1; i >= 0; --i) {
    if (used.at(i)) {
      continue;
    }
    used.at(i) = true;
    ll pow2 = 1;
    while (pow2 <= A.at(i)) {
      pow2 *= 2;
    }
    ll need = pow2 - A.at(i);
    ll l = lower_bound(A.begin(), A.end(), need) - A.begin() - 1;
    ll r = upper_bound(A.begin(), A.end(), need) - A.begin();
    r = min(r, i);
    // cout << "nned" << need << endl;
    // cout << l << ' ' << r << endl;
    if (l == r) {
      continue;
    }
    while (l + 1 != r) {
      ll m = (l + r) / 2;
      if (used.at(m)) {
        l = m;
      }
      else {
        r = m;
      }
    }
    // cout << "l" << l << "r" << r << endl;
    if (r == N) {
      continue;
    }
    if (A.at(r) != need) {
      continue;
    }
    if (used.at(r)) {
      continue;
    }
    used.at(r) = true;
    ans += 1;
    // for (ll j = l; j < r; ++j) {
    //   if (!used.at(j)) {
    //     used.at(j) = true;
    //     ans += 1;
    //     break;
    //   }
    // }
  }
  cout << ans << endl;
}
