#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int w, h, field[20][20];

int solve(int x, int y, int t)
{
  if (t > 9)
    return INF;

  int ans = INF;
  for (int i = 0; i < 4; ++i) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx < 0 || xx >= w || yy < 0 || yy >= h || field[yy][xx] == 1)
      continue;

    bool infield = true;
    while (field[yy][xx] == 0) {
      xx += dx[i];
      yy += dy[i];
      if (xx < 0 || xx >= w || yy < 0 || yy >= h) {
	infield = false;
	break;
      }
    }
    if (!infield)
      continue;

    if (field[yy][xx] == 3)
      return t+1;

    if (field[yy][xx] == 1) {
      field[yy][xx] = 0;
      ans = min(ans, solve(xx-dx[i], yy-dy[i], t+1));
      field[yy][xx] = 1;
    }
  }
  return ans;
}

int main()
{
  while (scanf("%d %d", &w, &h) != EOF) {
    if (w == 0 && h == 0)
      break;

    int x, y;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
	scanf("%d", &field[i][j]);
	if (field[i][j] == 2) {
	  x = j;
	  y = i;
	  field[i][j] = 0;
	}
      }
    }

    int ans = solve(x, y, 0);
    if (ans == INF)
      ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}