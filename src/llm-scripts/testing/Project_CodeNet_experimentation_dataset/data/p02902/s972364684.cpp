#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1001, M = 2001;
int n, m, a, b;
vector<int> edge[N];
vector<int> path;
unordered_map<int, int> mp;

bool check(int from, int to) {
  int s = mp[from];
  int e = mp[to];
  // index [s, e] in path
  for (int i = s; i <= e; ++i) {
    int cur = path[i];
    int next = (i == e ? path[s] : path[i + 1]);
    for (int v : edge[cur]) {
      if (v != next) {
        if (mp.count(v) && mp[v] >= s) {
          return false;
        }
      }
    }
  }
  return true;
}

void dfs(int u) {
  for (int v : edge[u]) {
    if (mp.count(v)) {
      // find cycle
      if (check(v, u)) {
        int s = mp[v];
        int e = mp[u];
        cout << e - s + 1 << endl;
        for (int i = s; i <= e; ++i) {
          cout << path[i] << endl;
        }
        exit(0);
      }
    } else {
      path.push_back(v);
      mp[v] = path.size() - 1;
      dfs(v);
      mp.erase(v);
      path.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    edge[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i) {
    path.push_back(i);
    mp[i] = 0;
    dfs(i);
    mp.erase(i);
    path.pop_back();
  }
  cout << -1 << endl;
  return 0;
}
