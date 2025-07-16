#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
char str[1005];
const int DR[4] = {0, 1, 0, -1};
const int DC[4] = {1, 0, -1, 0};
int sp[1005][1005];
int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	memset(sp, -1, sizeof(sp));
	queue<pair<int, int>> Q;
	for (int i = 0; i < h; ++i) {
		scanf("%s", str);
		for (int j = 0; j < w; ++j) {
			if (str[j] == '#') {
				sp[i][j] = 0;
				Q.push({i, j});
			}
		}
	}
	int ans = 0;
	while (!Q.empty()) {
		auto x = Q.front();
		Q.pop();
		ans = sp[x.first][x.second];
		for (int d = 0; d < 4; ++d) {
			int nr = x.first + DR[d];
			int nc = x.second + DC[d];
			if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
			if (sp[nr][nc] != -1) continue;
			sp[nr][nc] = sp[x.first][x.second] + 1;
			Q.push({nr, nc});
		}
	}
	printf("%d\n", ans);
}
