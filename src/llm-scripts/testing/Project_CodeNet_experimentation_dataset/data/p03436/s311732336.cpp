#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
const ll mod = 1e9+7;
const ll INF = 1e18;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;
using V = vector<ll>;
using P = pair<ll,ll>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i,h) cin >> grid[i];
  Graph d(h, V(w,-1));
  ll sy = 0, sx = 0, gy = h-1, gx = w-1;
  d[sy][sx] = 0;
  queue<P> q;
  vector dy = {0,1,0,-1};
  vector dx = {1,0,-1,0};

  q.push(make_pair(sy,sx));
  while(!q.empty()) {
    ll y = q.front().first, x = q.front().second;
    if (d[gy][gx] != -1) break;
    rep(i,4) {
      ll ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
      if (grid[ny][nx] == '.' && d[ny][nx] == -1) {
        d[ny][nx] = d[y][x]+1;
        q.push(make_pair(ny,nx));
      }
    }
    q.pop();
  }
  
  ll cnt = 0;
  rep(i,h) rep(j,w) {
    if (grid[i][j] == '.') ++cnt;
  }

  if (d[gy][gx] == -1) cout << -1 << '\n';
  else cout << cnt - d[gy][gx] - 1 << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}