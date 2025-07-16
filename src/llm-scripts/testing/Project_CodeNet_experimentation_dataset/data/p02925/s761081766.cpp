#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef std::pair<int, int> P;

bool is_vis[1003][1003];
bool is_fin[1003][1003];
bool is_cycle;

void dfs(map<P, vector<P>> &g, P p) {
  int player1 = p.first;
  int player2 = p.second;

  is_vis[player1][player2] = true;

  for (int i = 0; i < (int)g[p].size(); i++) {
    P nxt = g[p][i];
    int nxt_player1 = nxt.first;
    int nxt_player2 = nxt.second;

    if (is_fin[nxt_player1][nxt_player2]) {
      continue;
    }
    if (is_vis[nxt_player1][nxt_player2] && !is_fin[nxt_player1][nxt_player2]) {
      is_cycle = true;
      return;
    }
    dfs(g, nxt);
  }
  is_fin[player1][player2] = true;
}

int dp[1003][1003];
int rec(map<P, vector<P>> &g, P p) {
  int player1 = p.first;
  int player2 = p.second;
  if (dp[player1][player2] != -1) {
    return dp[player1][player2];
  }
  int res = 0;
  for (int i = 0; i < (int)g[p].size(); i++) {
    res = max(res, rec(g, g[p][i]) + 1);
  }
  return dp[player1][player2] = res;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  map<P, vector<P>> g;

  vector<vector<int>> A(n, vector<int>(n - 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - 1; j++) {
      int pre_1 = i + 1, pre_2 = A[i][j - 1];
      if (pre_1 > pre_2) {
        swap(pre_1, pre_2);
      }
      int nxt_1 = i + 1, nxt_2 = A[i][j];
      if (nxt_1 > nxt_2) {
        swap(nxt_1, nxt_2);
      }
      g[make_pair(pre_1, pre_2)].push_back(make_pair(nxt_1, nxt_2));
    }
  }

  // 閉路検出の処理
  // https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-サイクル検出
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= j) {
        continue;
      }
      if (g.find(make_pair(i, j)) == g.end()) {
        continue;
      }
      if (is_vis[i][j]) {
        continue;
      }
      is_cycle = false;
      dfs(g, make_pair(i, j));
      if (is_cycle) {
        cout << -1 << "\n";
        return 0;
      }
    }
  }

  for (int i = 0; i < 1003; i++) {
    for (int j = 0; j < 1003; j++) {
      dp[i][j] = -1;
    }
  }
  // 最長経路を求める
  // EDPC (https://atcoder.jp/contests/dp/tasks/dp_g) で見た
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= j) {
        continue;
      }
      ans = max(ans, rec(g, make_pair(i, j)) + 1);
    }
  }
  cout << ans << "\n";

  return 0;
}