#pragma GCC optmize(3)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctime>
#define rus register unsigned short
#define rs register short
using namespace std;

const int N = 15;

int G[N][N], dp[N][1 << N], cost[N][1 << N];
int n, m;

inline void upd(int &x, int y) {
  if (x == -1) x = y;
  else x = min(x, y);
}

inline int set_set(int x, int y) {
  int ret = 0;
  for (rs i = 0; i < n; i ++)
    if (x & (1 << i)) ret += cost[i][y];
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y, z; i <= m; i ++) {
    scanf("%d%d%d", &x, &y, &z);
    x --; y --;
    G[x][y] = G[y][x] = z;
  }
  int t = 1 << n;
  for (rus s = 1; s < t; s ++)
    for (rs i = 0; i < n; i ++)
      if (s & (1 << i)) {
	for (rs j = 0; j < n; j ++) cost[j][s] += G[i][j];
      }
  dp[0][1] = 0;
  for (rus s = 1; s < t; s += 2) {
    rus u = s ^ (t - 1);
    for (rs i = 0; i < n; i ++)
      if (s & (1 << i)) {
	if (dp[i][s] == -1) continue;
	for (rs j = 0; j < n; j ++)
	  if (!(s & (1 << j)) && G[i][j]) upd(dp[j][s | (1 << j)], dp[i][s] + cost[j][s ^ (1 << i)]);
	for (rus v = u; v; v = (v - 1) & u)
	  upd(dp[i][v | s], dp[i][s] + set_set(v, s ^ (1 << i)));
      }
  }
  printf("%d\n", dp[n - 1][t - 1]);
  return 0;
}
