#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
constexpr int INF = 1e9;
constexpr long long INFLL = 1LL<<60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w; cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<vector<int>> ans;

  rep(i, h) {
    rep(j, w) {
      if (a[i][j] % 2 == 0) continue;
      if (j < w-1) {
        ans.push_back({i, j, i, j+1});
        a[i][j+1]++;
      } else if (i < h-1) {
        ans.push_back({i, j, i+1, j});
        a[i+1][j]++;
      }
    }
  }

  cout << ans.size() << endl;
  for (auto& v : ans) {
    for (int j = 0; j < v.size(); j++) {
      cout << v[j] + 1;
      if (j == v.size() - 1) cout << endl;
      else cout << " ";
    }
  }

  return 0;
}
