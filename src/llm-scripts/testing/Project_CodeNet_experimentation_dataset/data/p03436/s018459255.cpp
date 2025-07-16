#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void MAIN() {
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  vector<string> s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "-" + s[i];
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') cnt++;
    }
  }
  vector<vector<int>> v(n + 1, vector<int>(m + 1));
  struct tup {
    int fi, sc, th;
    tup() {}
    tup(int fi, int sc, int th):
      fi(fi), sc(sc), th(th) {}
  };
  vector<int> r = {-1, 0, 1, 0};
  vector<int> c = {0, -1, 0, 1};
  queue<tup> q;
  q.push(tup(1, 1, 1));
  while (q.size()) {
    int x = q.front().fi;
    int y = q.front().sc;
    int z = q.front().th;
    q.pop();
    if (x < 1 || x > n || y < 1 || y > m) continue;
    if (v[x][y] || s[x][y] == '#') continue;
    v[x][y] = z;
    for (int i = 0; i < 4; i++) {
      q.push(tup(x + r[i], y + c[i], z + 1));
    }
  }
  if (v[n][m] == 0) {
    cout << -1 << '\n';
    return;
  }
  cout << n * m - cnt - v[n][m] << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  // ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
