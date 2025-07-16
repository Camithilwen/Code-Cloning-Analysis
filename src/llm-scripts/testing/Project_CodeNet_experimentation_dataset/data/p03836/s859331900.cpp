#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  for (int i = sy; i < ty; i++) cout << 'U';
  for (int i = sx; i < tx; i++) cout << 'R';
  for (int i = sy; i < ty; i++) cout << 'D';
  for (int i = sx; i < tx; i++) cout << 'L';
  cout << 'L';
  for (int i = sy; i <= ty; i++) cout << 'U';
  for (int i = sx; i <= tx; i++) cout << 'R';
  cout << 'D';
  cout << 'R';
  for (int i = sy; i <= ty; i++) cout << 'D';
  for (int i = sx; i <= tx; i++) cout << 'L';
  cout << 'U';
  cout << '\n';
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
