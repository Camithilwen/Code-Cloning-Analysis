#include<iostream>
#include<queue>
using namespace std;
int main() {
	int w, h, sx, sy, gx, gy, n;
	while (cin >> w >> h, w) {
		cin >> sx >> sy >> gx >> gy >> n;
		int map[110][110] = {};
		for (int i = 0; i < n; i++) {
			int c, d, x, y; cin >> c >> d >> x >> y;
			map[x][y] = c;
			map[x][y + 1] = c;
			map[x + 1][y] = c;
			map[x + 1][y + 1] = c;
			if (d == 0) {
				map[x + 2][y] = c;
				map[x + 2][y + 1] = c;
				map[x + 3][y] = c;
				map[x + 3][y + 1] = c;
			}
			else {
				map[x][y + 2] = c;
				map[x + 1][y + 2] = c;
				map[x][y + 3] = c;
				map[x + 1][y + 3] = c;
			}
		}
		queue<pair<int, int> >q;
		int p = map[sx][sy];
		if (p == 0)goto museum;
		q.push(make_pair(sx, sy));
		while (q.size()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			map[x][y] = 0;
			if (x == gx&&y == gy)goto heaven;
			if (map[x][y - 1] == p)q.push(make_pair(x, y - 1));
			if (map[x][y + 1] == p)q.push(make_pair(x, y + 1));
			if (map[x - 1][y] == p)q.push(make_pair(x - 1, y));
			if (map[x + 1][y] == p)q.push(make_pair(x + 1, y));
		}
		museum:cout << "NG\n"; goto park;
	heaven:cout << "OK\n";
	park:;
	}
}