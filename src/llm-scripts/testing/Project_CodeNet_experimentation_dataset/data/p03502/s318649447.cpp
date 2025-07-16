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

int f(int n) {
  int ret = 0;
  while (n) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

void MAIN() {
  int n; cin >> n;
  if (n % f(n) == 0) cout << "Yes" << '\n';
  else cout << "No" << '\n';
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
