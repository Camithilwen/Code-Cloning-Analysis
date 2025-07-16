#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  vector<ll> csum{0};
  partial_sum(va.begin(), va.end(), back_inserter(csum));
  map<ll, ll> cnts;
  for (auto s : csum) {
    cnts[s % m]++;
  }

  ll ans = 0;
  for (auto &p : cnts) {
    ans += (p.second * (p.second - 1)) / 2;
  }

  cout << ans << '\n';
  return 0;
}