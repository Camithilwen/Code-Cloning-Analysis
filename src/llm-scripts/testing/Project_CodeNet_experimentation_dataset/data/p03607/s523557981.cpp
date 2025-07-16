#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  map<ll, int> a;
  rep(i, n) {
    ll temp;
    cin >> temp;
    a[temp]++;
  }

  ll ans = 0;
  for (auto x : a) {
    if (x.second % 2 != 0) ans++;
  }

  cout << ans << endl;
  
  return 0;
}