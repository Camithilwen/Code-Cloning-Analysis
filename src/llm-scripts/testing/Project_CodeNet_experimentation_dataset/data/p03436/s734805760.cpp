#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int h, w, dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
vector<string>m;

int main() {
	cin >> h >> w;
	m.resize(h);
	int sum = 0;
	for (int i = 0; i < h; i++) {
		cin >> m[i];
		for (int j = 0; j < w; j++) {
			if (m[i][j] == '.')sum++;
		}
	}
	
	vector<vector<int>>d(h, vector<int>(w, 0));
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
			if (m[nx][ny] == '#'||d[nx][ny])continue;
			q.push({ nx,ny });
			d[nx][ny] = d[x][y] + 1;
		}
	}
	if (d[h - 1][w - 1]) {
		cout << sum - (d[h - 1][w - 1] + 1) << endl;
	}
	else cout << -1 << endl;

	return 0;
}