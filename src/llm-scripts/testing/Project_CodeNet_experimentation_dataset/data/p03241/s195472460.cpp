// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  ll n, m; cin >> n >> m;
  vector<ll> D;
  for (ll i=1; i*i<=m; i++) {
    if (m%i == 0) {
      D.push_back(i);
      if (i*i<=m) D.push_back(m/i);
    }
  }
  
  sort(D.rbegin(), D.rend());
  
  for (auto &&d: D) {
    if (n*d <= m) {
      cout << d << endl;
      return 0;
    }
  }
  
  cout << -1 << endl;
  return 0;
}
