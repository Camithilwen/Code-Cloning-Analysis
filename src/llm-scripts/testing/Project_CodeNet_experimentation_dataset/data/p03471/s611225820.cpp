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
  int n, y;
  cin >> n >> y;
  for (int i = 0; i <= n; i++)
  for (int j = 0; j <= n - i; j++) {
    int k = n - i - j;
    if (10000 * i + 5000 * j + 1000 * k == y) {
      cout << i << ' ' << j << ' ' << k << '\n';
      return;
    }
  }
  cout << "-1 -1 -1" << '\n';
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
