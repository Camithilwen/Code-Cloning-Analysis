#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

struct UnionFind {
  vector<int> parent;
  vector<int> num_node;

  UnionFind(int N) : parent(N), num_node(N, 1) {
    for (int i = 0; i < N; i++) {
      parent[i] = i;
    }
  }

  // 根を求める
  int root(int x) {
    if (parent[x] == x) {
      return x;
    }

    // 経路圧縮
    parent[x] = root(parent[x]);
    return parent[x];
  }

  // 同一判定
  bool is_same(int x, int y) {
    return this->root(x) == this->root(y);
  }

  // 併合
  void unite(int x, int y) {
    x = this->root(x);
    y = this->root(y);

    // すでに一緒ならなにもしない
    if (x == y) {
      return;
    }
    parent[x] = y;
    num_node[y] += num_node[x];
  }

  // 同一グループのノード数
  int size(int x) {
    return num_node[root(x)];
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll h, w;
  cin >> h >> w;
  vs s(h);
  rep(i, h) {
    cin >> s[i];
  }

  ll n = h * w;
  UnionFind uf(n);
  vector<vb> visited(h, vb(w));

  rep(i, n) {
    ll y = i / w;
    ll x = i % w;

    if (visited[y][x]) {
      continue;
    }

    queue<P> q;
    q.push(make_pair(y, x));

    while (!q.empty()) {
      auto it = q.front();
      q.pop();

      ll v = it.first * w + it.second;
      uf.unite(i, v);

      ll y = it.first;
      ll x = it.second;

      if (y > 0) {
        if (!visited[y - 1][x] && s[y - 1][x] != s[y][x]) {
          q.push(make_pair(y - 1, x));
          visited[y - 1][x] = true;
        }
      }
      if (y < h - 1) {
        if (!visited[y + 1][x] && s[y + 1][x] != s[y][x]) {
          q.push(make_pair(y + 1, x));
          visited[y + 1][x] = true;
        }
      }

      if (x > 0) {
        if (!visited[y][x - 1] && s[y][x - 1] != s[y][x]) {
          q.push(make_pair(y, x - 1));
          visited[y][x - 1] = true;
        }
      }
      if (x < w - 1) {
        if (!visited[y][x + 1] && s[y][x + 1] != s[y][x]) {
          q.push(make_pair(y, x + 1));
          visited[y][x + 1] = true;
        }
      }
    }
  }

  vector<P> vp(n);

  rep(i, n) {
    ll y = i / w;
    ll x = i % w;
    if (s[y][x] == '.')
      vp[uf.root(i)].first++;
    else
      vp[uf.root(i)].second++;
  }

  ll ans = 0;
  rep(i, n) {
    ans += vp[i].first * vp[i].second;
  }

  cout << ans << endl;

  return 0;
}
