#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100

struct in {
	int c;
	int d;
	pair<int, int> p;
};

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int w, h, n;
pair<int, int> st, gl;
int map[MAX+2][MAX+2];//map[X][Y]
vector<in> info;
bool f;

bool dfs(int x, int y, int c) {
	if (map[x][y] != c) return false;
	map[x][y] = -1;
	if (x==gl.first&&y==gl.second) return true;
	for (int i=0; i<4; i++) {
		if (x+dx[i]<0 || y+dy[i]<0 || x+dx[i]>=w+2 || y+dy[i]>=h+2) continue;
		if (dfs(x+dx[i], y+dy[i], c)) return true;
	}

	return false;
}

int main() {
	while (cin >> w >> h, w||h) {
		cin >> st.first >> st.second >> gl.first >> gl.second >> n;
		info.clear();
		for (int i=0; i<n; i++) {
			in t;
			cin >> t.c >> t.d >> t.p.first >> t.p.second;
			info.push_back(t);
		}

		memset(map, 0, sizeof(map));
		for (int i=0; i<n; i++) {
			int W=4, H=2;
			if (info[i].d) { int t=W; W=H; H=t; }
			for (int x=0; x<W; x++)
			for (int y=0; y<H; y++)
				map[info[i].p.first+x][info[i].p.second+y] = info[i].c;
		}

		cout << ((dfs(st.first, st.second, map[st.first][st.second])) ? "OK" : "NG") << endl;
	}
	return 0;
}