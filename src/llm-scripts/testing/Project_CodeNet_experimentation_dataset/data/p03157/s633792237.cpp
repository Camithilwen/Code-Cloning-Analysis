#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int h, w;
vector<string> s;

vector<int> G[160160];
bool visited[160160];

vector<ll> cnt;

void dfs(int v) {
  if (visited[v]) return;
  visited[v] = true;
  if (s[v / w][v % w] == '#') cnt[0]++;
  else cnt[1]++;
  for (int u: G[v]) {
    dfs(u);
  }
}

int main() {
  cin >> h >> w;
  s.resize(h);
  rep(i, h) cin >> s[i];

  rep(i, h) {
    rep(j, w) {
      rep(k, 4) {
        int ry = i + dy[k], rx = j + dx[k];
        if (ry < 0 || ry >= h || rx < 0 || rx >= w) continue;
        if (s[i][j] != s[ry][rx]) {
          G[i * w + j].push_back(ry * w + rx);
        }
      }
    }
  }
  ll ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (visited[i * w + j]) continue;
      cnt = vector<ll>(2, 0);
      dfs(i * w + j);
      ans += cnt[0] * cnt[1];
    }
  }
  cout << ans << endl;


  
  return 0;
}