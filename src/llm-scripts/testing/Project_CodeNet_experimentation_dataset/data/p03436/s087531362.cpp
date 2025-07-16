#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,P>;

vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};

int inf = 1000000000;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,0,h) cin >> s[i];
  priority_queue<PP, vector<PP>, greater<PP>> q;
  vector<vector<int>> dist(h, vector<int>(w, inf));
  dist[0][0] = 1;
  q.push(PP(0,P(0,0)));
  while(!q.empty()) {
    PP p = q.top(); q.pop();
    int x = p.se.fi, y = p.se.se;
    rep(i,0,4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (s[nx][ny] == '#') continue;
      if (dist[nx][ny] > dist[x][y] + 1) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push(PP(dist[nx][ny], P(nx, ny)));
      }
    }
  }
  if (dist[h-1][w-1] == inf) {
    cout << -1 << endl;
    return 0;
  }
  int hash = 0;
  rep(i,0,h) rep(j,0,w) if (s[i][j] == '#') hash++;
  int ans = h*w - hash - dist[h-1][w-1];
  cout << ans << endl;
  return 0;
}
