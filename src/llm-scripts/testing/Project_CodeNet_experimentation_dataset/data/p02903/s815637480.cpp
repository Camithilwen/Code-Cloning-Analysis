#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w, a, b;
  cin >> h >> w >> a >> b;

  bool refl = true;
  for (int i = 0; i < h; i++) {
    int p = 0, q = 1;
    if (!refl) swap(p, q);
    for (int j = 0; j < w; j++) {
      if (j < a) cout << p;
      else cout << q;
    }
    cout << endl;
    if (i == b-1) refl = !refl;
  }
}
