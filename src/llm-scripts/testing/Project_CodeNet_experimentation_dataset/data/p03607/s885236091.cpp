#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    if (s.count(t)) s.erase(t);
    else s.insert(t);
  }
  cout << s.size() << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
