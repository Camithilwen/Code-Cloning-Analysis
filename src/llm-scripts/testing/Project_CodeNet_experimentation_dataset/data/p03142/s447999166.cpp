#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> to(N+1);
  vector<vector<int>> from(N+1);
  vector<bool> visited(N+1);
  vector<int> parent(N+1);


  for (int i = 0; i < N-1+M; i++) {
    int a, b; cin >> a >> b;
    to[b].push_back(a);
    from[a].push_back(b);
  }

  int root = 1;
  while (!to[root].empty()) {
    root++;
  }

  visited[root] = true;
  parent[root] = 0;

  queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int x = q.front(); q.pop();
    visited[x] = true;

    for (int dist : from[x]) {
      bool ok = true;
      for (int y : to[dist]) {
        if (!visited[y]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        q.push(dist);
        parent[dist] = x;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << parent[i] << endl;
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
