#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;
vector<int> indeg;  // 入次数
vector<bool> visited;
vector<int> ans;  // トポロジカルソートの結果

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited.at(s) = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nx : G.at(cur)) {
      indeg.at(nx)--;
      if (indeg.at(nx) == 0 && !visited.at(nx)) {
        q.push(nx);
        ans.at(nx) = cur + 1;
      }
    }
  }
}


int main() {
  cin >> N >> M;
  G.resize(N);
  for (int i = 0; i < N-1+M; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
  }

  indeg.resize(N);
  visited.resize(N);
  ans.resize(N);
  for (int i = 0; i < N; i++) {
    for (int e : G.at(i)) {
      indeg.at(e)++;
    }
  }
  for (int i = 0; i < N; i++) {
    if (indeg.at(i) == 0 && !visited.at(i)) bfs(i);
  }
  for (int v : ans) cout << v << endl;
}