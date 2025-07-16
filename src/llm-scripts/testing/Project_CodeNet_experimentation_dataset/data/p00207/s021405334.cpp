#include <bits/stdc++.h>

using namespace std;

int mp[101][101];
int w, h;
int gx, gy;

int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

bool dfs(int y, int x, int c)
{
	if (y < 1 || y > h || x < 1 || x > w || mp[y][x] != c) return false;

	if (y == gy && x == gx) return true;

	mp[y][x] = 0;

	bool res = false;

	for (int i = 0; i < 4; ++i) res = res || dfs(y + dy[i], x + dx[i], c);

	return res;
}

int main()
{
	while (cin >> w >> h, w || h) {
		int sx, sy;
		cin >> sx >> sy >> gx >> gy;
		int n; cin >> n;
		while (n--) {
			int c, d, x, y; cin >> c >> d >> x >> y;
			if (d) {
				for (int i = 0; i < 4; ++i) for (int j = 0; j < 2; ++j) mp[y+i][x+j] = c;
			} else {
				for (int i = 0; i < 2; ++i) for (int j = 0; j < 4; ++j) mp[y+i][x+j] = c;
			}
		}

		cout << (dfs(sy, sx, mp[sy][sx]) ? "OK" : "NG") << endl;
	}
}