#include <iostream>
#include <map>

using namespace std;

typedef pair<int, int> P;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int W, H;
int curl[22][22];
int ans;
P s;

bool inCurl(int x, int y)
{
  return (x >= 0 && y >= 0 && x < W && y < H);
}

void dfs(int x, int y, int n)
{
  if (n >= ans)
    return;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (!inCurl(nx, ny))
      continue;
    if (curl[ny][nx] == 1) 
      continue;

    while (true) {
      if (curl[ny][nx] == 3) {
	ans = n;
	return;
      }
      nx += dx[i];
      ny += dy[i];
      
      if (!inCurl(nx, ny)) 
	break;

      if (curl[ny][nx] == 1) {
	curl[ny][nx] = 0;
	dfs(nx - dx[i], ny - dy[i], n + 1);
	curl[ny][nx] = 1;
	break;
      }
    }
  }
}

int main()
{
  while (cin >> W >> H, W && H) {
    // Input
    for (int y = 0; y < H; y++) 
      for (int x = 0; x < W; x++) {
	cin >> curl[y][x];
	if (curl[y][x] == 2) {
	  s.first = x;
	  s.second = y;
	  curl[y][x] = 0;
	}
      }

    ans = 11;
    dfs(s.first, s.second, 1);
    if (ans > 10)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }

  return 0;
}