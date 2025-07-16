#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define I1000000007 (1000000007)
#define I998244353   (998244353)
#define IINF             (1<<28)
#define LINF           (1LL<<60)
#define ALL(a)         (a).begin(), (a).end()
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"
template<class T> inline bool chmin(T& a, const T& b) {
  if (a > b) { a = b; return true; } else return false;
}
template<class T> inline bool chmax(T& a, const T& b) {
  if (a < b) { a = b; return true; } else return false;
}

namespace solver {
  using namespace std;
  using ll = long long;

  ll N, M;
  vector<int> color;
  vector<vector<int> > G;

  void init() {
    cin >> N >> M;
    color.resize(N);
    G.resize(N);
    int a, b;
    rep(i, M) {
      cin >> a >> b;
      a--;
      b--;
      G[a].push_back(b);
      G[b].push_back(a);
    }
  }

  bool dfs(int u, int c) {
    color[u] = c;
    for(const auto& v : G[u]) {
      if(color[u] == color[v]) return false;
      if(color[v] == 0 && !dfs(v, -c)) return false;
    }
    return true;
  }

  void solve() {
    fill(ALL(color), 0);
    if(dfs(0, 1)) {
      ll b = 0;
      ll w = 0;
      for(const auto& c : color) {
        if(c == 1) b++;
        else w++;
      }
      cout << b*w - M << "\n";
    } else {
      cout << N*(N-1)/2 - M << "\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}