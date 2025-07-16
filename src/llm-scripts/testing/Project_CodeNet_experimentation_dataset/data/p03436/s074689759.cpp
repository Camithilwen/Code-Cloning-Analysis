#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int h, w;
	cin >> h >> w;
	vector<string> v(h);
	rep(i,h) cin >> v[i];
	vector<vector<int>> d(h, vector<int>(w, INF));
	queue<pii> q;
	auto update = [&](int y, int x, int nd) {
		if (d[y][x] != INF) return;
		d[y][x] = nd;
		q.push(pii(y, x));
	};

	update(0, 0, 1);
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		rep(i,4) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if (v[ny][nx] == '#') continue;
			update(ny, nx, d[p.first][p.second] + 1);
		}
	}
	if (d[h-1][w-1] == INF) {
		cout << -1 << endl;
	} else {
		int cs = 0;
		rep(i,h) rep(j,w) if (v[i][j] == '#') cs++;
		// cout << h * w << " " << cs << " " << d[h-1][w-1] << endl;
		cout << h * w - (cs + d[h-1][w-1]) << endl;
	}
}

int main() {
	solve();
	return 0;
}