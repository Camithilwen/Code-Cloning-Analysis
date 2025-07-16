#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
  }
  vector<bool> vis(N);
  vector<int> path;
  vector<int> ans;
  function<void(int, int)> dfs = [&](int tmp, int par) {
    if(vis[tmp]) {
      auto from = find(all(path), tmp);
      int size = path.end() - from;
      if(size != 0) {
        if(ans.size() == 0 || size < (int)ans.size()) {
          ans = vector<int>(size);
          copy(from, path.end(), ans.begin());
        }
      }
      return;
    }
    path.push_back(tmp);
    vis[tmp] = true;
    for(int ne: G[tmp]) dfs(ne, tmp);
    path.pop_back();
  };
  rep(i, N) dfs(i, -1);
  if(ans.size() == 0) {
    cout << -1 << endl;
  } else {
    auto check = [&](vector<int>& path) {
      set<int> se;
      for(int v: path) se.insert(v);
      int n = path.size();
      rep(i, n) {
        for(int ne: G[path[i]]) {
          if(se.count(ne) && ne != path[(i+1)%n]) {
            return make_pair(path[i], ne);
          }
        }
      }
      return make_pair(-1, -1);
    };

    while(true) {
      auto ret = check(ans);
      if(ret.first == -1) break;
      vector<int> newPath;
      int n = ans.size();
      int begin = find(all(ans), ret.second) - ans.begin();
      int end = find(all(ans), ret.first) - ans.begin();
      for(int i=begin; i!=end; i=(i+1)%n) {
        newPath.push_back(ans[i]);
      }
      newPath.push_back(ans[end]);
      ans = vector<int>(newPath.size());
      copy(all(newPath), ans.begin());
    }
    cout << ans.size() << endl;
    for(int a: ans) cout << a+1 << endl;
  }
  return 0;
}
