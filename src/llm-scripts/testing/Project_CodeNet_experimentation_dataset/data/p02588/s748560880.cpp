#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n;
  cin >> n;
  int ans = 0;
  map<pair<int, int>, int> m;
  for (int i = 0; i < n; i++) {
    double _; cin >> _;
    int t = llround(_ * 1e9);
    int ct = 0, cf = 0;
    while (t % 2 == 0) {
      t /= 2;
      ct++;
    }
    while (t % 5 == 0) {
      t /= 5;
      cf++;
    }
    for (auto &j : m) {
      if (j.fi.fi + ct >= 18 && j.fi.sc + cf >= 18) {
        ans += j.sc;
      }
    }
    m[ii(ct, cf)]++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
