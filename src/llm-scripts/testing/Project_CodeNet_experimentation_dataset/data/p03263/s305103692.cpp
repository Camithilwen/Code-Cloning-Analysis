#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 501;

int a[N][N];

struct Move {
  int x1, y1, x2, y2;
};

            // up, left, down, right
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

void solve() {
  int h, w; scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf("%d", a[i]+j);
    }
  }
  vector<Move> v;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j]%2 == 0) continue;
      for (int k = 0; k < 4; ++k) {
	if (i+dy[k] < 0 || i+dy[k] >= h || j+dx[k] < 0 || j+dx[k] >= w) continue;
	if (a[i+dy[k]][j+dx[k]]%2==0) continue;
	v.push_back({i+1, j+1, i+dy[k]+1, j+dx[k]+1});
	--a[i][j];
	++a[i+dy[k]][j+dx[k]];
	break;
      }
      if (a[i][j]%2 == 0) continue;
      for (int k = 2; k < 4; ++k) {
	if (i+dy[k] < 0 || i+dy[k] >= h || j+dx[k] < 0 || j+dx[k] >= w) continue;
	v.push_back({i+1, j+1, i+dy[k]+1, j+dx[k]+1});
	--a[i][j];
	++a[i+dy[k]][j+dx[k]];
	break;
      }
    }
  }
  printf("%d\n", v.size());
  for (const auto &e: v) {
    printf("%d %d %d %d\n", e.x1, e.y1, e.x2, e.y2);
  }
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
