#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long
using P = pair<int,int>;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int N = 405;
const int INF = 1e9;
char board[N][N];
int h,w;

bool is_in(int x, int y) {
  if(0 <= x && x < h && 0 <= y && y < w) return true;
  return false;
}

signed main() {
  cin >> h >> w;

  rep(i,h) rep(j,w) cin >> board[i][j];
  vector<vector<int>> d(h, vector<int> (w, INF));

  int ans = 0;
  rep(ii,h) rep(jj,w) {
    if(board[ii][jj] != '#' || d[ii][jj] != INF) continue;
    int sx = ii, sy = jj;

    queue<P> que;
    d[sx][sy] = 0;
    que.push({sx,sy});

    int cnt = 0;
    int black = 1;
    while(!que.empty()) {
      int cx = que.front().first;
      int cy = que.front().second;
      que.pop();

      for (int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(!is_in(nx, ny)) continue;
        if(board[nx][ny] == board[cx][cy] || d[nx][ny] != INF) continue;

        if(board[nx][ny] == '.') cnt++;
        else if(board[nx][ny] == '#') black++;

        d[nx][ny] = d[cx][cy] + 1;
        que.push({nx, ny});
      }
    }

    ans += cnt * black;
  }
  cout << ans << '\n';
}
