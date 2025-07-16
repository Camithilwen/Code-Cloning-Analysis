#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 400;
 
int h, w;
string s;
 
int grid[MX][MX];
ll black[MX*MX], white[MX*MX];
bool used[MX][MX];
ll ans;
 
int curGroup = -1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
 
void dfs(int x, int y) {
	used[x][y] = true;
	if (grid[x][y]) black[curGroup]++;
	else white[curGroup]++;
	for (int i = 0; i < 4; i++) {
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= h || b < 0 || b >= w) continue;
		if (grid[a][b] == grid[x][y]) continue;
		if (used[a][b]) continue;
		dfs(a, b);
	}
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == '#') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			curGroup++;
			if (!used[i][j]) dfs(i, j);
		}
	}
	
	for (int i = 0; i <= curGroup; i++) {
		ans += white[i] * black[i];
	}
	cout << ans;
    return 0;
}
