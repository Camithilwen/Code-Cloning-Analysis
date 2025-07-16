#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n-1+m), b(n-1+m), in(n);
  vector<vector<int>> G(n);
  for (int i = 0; i < n+m-1; ++i) {
    cin >> a[i] >> b[i];
    a[i] --, b[i] --;
    G[a[i]].push_back(b[i]);
    in[b[i]] ++;
  }

  int root = -1;
  int edge = n+m-1;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0) {
      root = i;
      break;
    }
  }

  queue<int> que;
  que.push(root);
  vector<int> dist(n);

  while (!que.empty()) {
    auto now = que.front();
    que.pop();

    for (auto to : G[now]) {
      chmax(dist[to], dist[now] + 1);
      in[to] --;
      if (in[to] == 0) {
        // 根の子の入次数は1だから必ずここには入る
        // 親に対しても有向辺を貼る可能性はないので途中で探索が終わることもない
        que.push(to);
      }
    }
  }

  vector<int> ans(n, 0);
  for (int i = 0; i < n; ++i) {
    for (auto&& to : G[i]) {
      if (dist[to] - dist[i] == 1) {
        ans[to] = i+1;
      }
    }
  }

  for (auto it : ans) {
    cout << it << endl;
  }
}