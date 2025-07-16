#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 1e3+23;

int n;
int bio[N][N];
int a[N][N];
int dp[N][N];
vector<pair<int, int>> g[N][N];

int dfs(int x, int y) {
  int &ret = dp[x][y];
  if (ret) return ret;
  bio[x][y] = 1;
  ret = 1;
  for (const auto &v: g[x][y]) {
    if (bio[v.first][v.second] == 1) {
      printf("-1");
      exit(0);
    }
    ret = max(ret, 1+dfs(v.first, v.second));
  }
  bio[x][y] = 2;
  return ret;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n-1; ++j) {
      scanf("%d", a[i]+j);
      --a[i][j];
      if (j) {
	g[min(i, a[i][j-1])][max(i, a[i][j-1])]
	  .emplace_back(min(i, a[i][j]), max(i, a[i][j]));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (bio[i][j]) continue;
      ans = max(ans, dfs(i, j));
    }
  }
  printf("%d", ans);

}
int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
