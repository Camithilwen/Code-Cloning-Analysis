#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), d;
  rep(i, n) cin >> a[i];

  rep(i, n) {
    auto itr = lower_bound(d.rbegin(), d.rend(), a[i]);
    if (itr == d.rbegin())
      d.push_back(a[i]);
    else
      *--itr = a[i];
  }
  cout << d.size() << endl;
  return 0;
}