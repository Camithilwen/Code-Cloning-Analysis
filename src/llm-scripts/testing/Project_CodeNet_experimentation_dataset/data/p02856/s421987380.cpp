#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

int g[10][10];
int f[10][10];

void solve() {
  int M;
  cin >> M;
  int ans = -1;
  int sum = 0;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int a = i+j;
      g[i][j] = a/10+a%10;
      f[i][j] = a >= 10 ? 2 : 1;
    }
  }

  int amari = 0;
  while (M--) {
    int c, d; cin >> d >> c;

    while (c > 1) {
      if (c%2 == 1) {
        c--;
        ans += f[amari][d];
        amari = g[amari][d];
      }

      c /= 2;
      ans += c * f[d][d];
      d = g[d][d];
    }

    ans += f[amari][d];
    amari = g[amari][d];
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
