// J'aime
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

void MAIN() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n), b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  sort(all(a));
  sort(all(b));
  if (a.back() < b.front() && a.back() < y && b.front() > x) cout << "No War" << '\n';
  else cout << "War" << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
