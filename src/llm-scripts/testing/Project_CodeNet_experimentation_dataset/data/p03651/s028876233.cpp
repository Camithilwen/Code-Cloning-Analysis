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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int g = a[0];
  for (int i = 1; i < n; i++) {
    g = __gcd(g, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= k && (a[i] - k) % g == 0) {
      cout << "POSSIBLE" << '\n';
      return;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
