#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int bfs(int sx, int sy, int gx, int gy, vector<string>& vs) {
  vector<vector<int>> d(vs.size(), vector<int>(vs[0].size(), -1));
  queue<P> que;

  que.push(P(sx, sy));
  d[sy][sx] = 0;

  while (que.size()) {
    P p = que.front(); que.pop();
    if (p.first == gx && p.second == gy) break;
    
    rep(i, 4) {
      int nx = p.first + dx[i], ny = p.second + dy[i];

      if (0 <= nx && nx < vs[0].size() &&
          0 <= ny && ny < vs.size() && 
          vs[ny][nx] != '#' && d[ny][nx] == -1) {
        d[ny][nx] = d[p.second][p.first] + 1;
        que.push(P(nx, ny));
      }
    }
  }

  return d[gy][gx];
}


int main(void) {
  int H, W;
  cin >> H >> W;
  vector<string> vs(H);
  rep(i, H) cin >> vs[i];

  // 幅優先探索で最短経路を求める
  int shortest = bfs(0, 0, W - 1, H - 1, vs);
  if (shortest == -1) {
    cout << -1 << endl;
    return 0;
  }
  int count = 0;  // 初期状態の白マス全て
  rep(i, H) rep(j, W) if (vs[i][j] == '.') ++count;
  // 全ての白マスから、最短経路を除外する
  count -= shortest + 1;

  cout << count << endl;

  
  return 0;
}