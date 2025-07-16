#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, q;
  string s;
  cin >> n >> s >> q;
  
  while (q--) {
    int k;
    cin >> k;
    
    vector<ll> d(n), m(n), dm(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (s.at(i) == 'D') d.at(i)++;
        if (s.at(i) == 'M') m.at(i)++;
        continue;
      }
      
      d.at(i) = d.at(i - 1);
      m.at(i) = m.at(i - 1);
      dm.at(i) = dm.at(i - 1);
      
      if (i >= k) {
        if (s.at(i - k) == 'D') {
          d.at(i)--;
          dm.at(i) -= m.at(i - 1);
        }
        if (s.at(i - k) == 'M') {
          m.at(i)--;
        }
      }
      
      if (s.at(i) == 'D') {
        d.at(i)++;
      }
      if (s.at(i) == 'M') {
        m.at(i)++;
        dm.at(i) += d.at(i);
      }
      if (s.at(i) == 'C') {
        ans += dm.at(i);
      }
    }
    
    cout << ans << '\n';
  }
}