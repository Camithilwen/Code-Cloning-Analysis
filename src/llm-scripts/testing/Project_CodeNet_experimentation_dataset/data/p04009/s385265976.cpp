#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
inline void chmax(int &x, int v) { if (x < v) x = v; }

int H, W;
int EX, EY;
char A[100][100];
int tate[100][100];
int yoko[100][100];
vector<vector<vector<vector<int> > > > dp;
inline int f_tate(int x, int l, int r) {
  l = max(l, 0);
  r = min(r, H-1);
  if (x<0||x>=W||l>r) return 0;
  return tate[x][r]-(l>0?tate[x][l-1]:0);
}
inline int f_yoko(int y, int l, int r) {
  l = max(l, 0);
  r = min(r, W-1);
  if (y<0||y>=H||l>r) return 0;
  return yoko[r][y]-(l>0?yoko[l-1][y]:0);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> H >> W;
  rep(i, H) rep(j, W) cin >> A[j][i];
  rep(x, W) rep(y, H) if (A[x][y] == 'E') EX = x, EY = y;
  rep(x, W) rep(y, H) tate[x][y] = yoko[x][y] = A[x][y] == 'o';
  rep(x, W-1) rep(y, H) yoko[x+1][y] += yoko[x][y];
  rep(x, W) rep(y, H-1) tate[x][y+1] += tate[x][y];

  dp.resize(W+1);
  rep(l, W+1) {
    dp[l].resize(W+1-l);
    rep(r, W+1-l) {
      dp[l][r].resize(H+1);
      rep(u, H+1) dp[l][r][u].resize(H+1-u, -INF);
    }
  }
  dp[0][0][0][0] = 0;
  rep(l, W) {
    rep(r, W-l) {
      rep(u, H) {
        rep(d, H-u) {
          if (dp[l][r][u][d] == -INF) continue;
          chmax(dp[l+1][r][u][d], dp[l][r][u][d] + ((EX-(l+1)<r)?0:f_tate(EX-(l+1), max(EY-u, d), min(EY+d, H-1-u))));
          chmax(dp[l][r+1][u][d], dp[l][r][u][d] + ((EX+(r+1)>=W-l)?0:f_tate(EX+(r+1), max(EY-u, d), min(EY+d, H-1-u))));
          chmax(dp[l][r][u+1][d], dp[l][r][u][d] + ((EY-(u+1)<d)?0:f_yoko(EY-(u+1), max(EX-l, r), min(EX+r, W-1-l))));
          chmax(dp[l][r][u][d+1], dp[l][r][u][d] + ((EY+(d+1)>=H-u)?0:f_yoko(EY+(d+1), max(EX-l, r), min(EX+r, W-1-l))));
        }
      }
    }
  }
  int m = 0;
  rep(l, W+1) rep(r, W+1-l) rep(u, H+1) rep(d, H+1-u) chmax(m, dp[l][r][u][d]);
  cout << m << "\n";
  return 0;
}
