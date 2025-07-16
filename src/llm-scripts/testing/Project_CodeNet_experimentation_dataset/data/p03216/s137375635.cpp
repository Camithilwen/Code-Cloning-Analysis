#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<int> lk(q);
  vector<ll> memo(n, 0);
  for (int &k: lk) cin >> k;
  for (int k : lk) {
    ll ans = 0;
    vector<ll> ls(3, 0);
    for (int i = 0; i < n; ++i) {
      if (i >= k) {
        if (s[i-k] == 'D') {
          --ls[0];
          ls[2] -= ls[1];
        }
        if (s[i-k] == 'M') --ls[1];
      }
      if (s[i] == 'D') ++ls[0];
      if (s[i] == 'M') {
        ++ls[1];
        ls[2] += ls[0];
      }
      if (s[i] == 'C') {
        ans += ls[2];
      }
    }
    cout << ans << endl;
  }
}

