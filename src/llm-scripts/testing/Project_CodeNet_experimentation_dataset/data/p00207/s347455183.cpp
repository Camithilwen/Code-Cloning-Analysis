#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>

int testcase_ends() {
  int w, h;
  scanf("%d %d", &w, &h);
  if (w == 0 && h == 0)
    return 1;

  int xs, ys;
  scanf("%d %d", &xs, &ys);

  int xg, yg;
  scanf("%d %d", &xg, &yg);

  std::vector<std::vector<int>> g(h+2, std::vector<int>(w+2));

  int n;
  scanf("%d", &n);

  for (int i=0; i<n; ++i) {
    int c, d, x, y;
    scanf("%d %d %d %d", &c, &d, &x, &y);

    int dh=2, dw=2;
    (d? dh:dw) += 2;

    for (int j=0; j<dh; ++j)
      for (int k=0; k<dw; ++k)
	g[y+j][x+k] = c;
  }

  // for (int i=0; i<h; ++i)
  //   for (int j=0; j<w; ++j)
  //     fprintf(stderr, "%d%c", g[i][j], j+1<w? ' ':'\n');

  if (g[ys][xs] != g[yg][xg])
    return !printf("NG\n");

  const int dy[]={-1, 0, 1, 0};
  const int dx[]={0, -1, 0, 1};
  std::function<bool (int, int)> dfs=[&](int x, int y) {
    if (x == xg && y == yg) return true;

    int cs=g[y][x];
    g[y][x] = -cs;  // mark visited
    for (int k=0; k<4; ++k) {
      int cd=g[y+dy[k]][x+dx[k]];
      if (cs == cd && dfs(x+dx[k], y+dy[k]))
	return true;
    }
    return false;
  };

  printf("%s\n", dfs(xs, ys)? "OK":"NG");
  return 0;
}      

int main() {
  while (!testcase_ends()) {}
}

