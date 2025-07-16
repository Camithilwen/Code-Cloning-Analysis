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
short S[105][105];
struct Rect {
	int x1, x2, y1, y2;
	inline bool valid() {
		return x2 >= x1 && y2 >= y1;
	}
	inline short gain() {
		return S[y2][x2] - S[y1 - 1][x2] - S[y2][x1 - 1] + S[y1 - 1][x1 - 1];
	}
};
Rect inter(const Rect& a, const Rect& b) {
	return {max(a.x1, b.x1), min(a.x2, b.x2), max(a.y1, b.y1), min(a.y2, b.y2)};
}
char G[105][105];
int H, W;
int ex, ey;
short dp[101][101][101][101];
short f(int x1, int x2, int y1, int y2) {
	short& ret = dp[x1][x2][y1][y2];
	if (ret != -1) return ret;
	int l = x2 - ex + 1;
	int r = x1 + (W - ex);
	int u = y2 - ey + 1;
	int d = y1 + (H - ey);
	ret = 0;
	Rect allow{l, r, u, d};
	Rect slice;
	slice = inter({x1 - 1, x1 - 1, y1, y2}, allow);
	if (slice.valid()) {
		ret = max((int)ret, f(x1 - 1, x2, y1, y2) + slice.gain());
	}
	slice = inter({x2 + 1, x2 + 1, y1, y2}, allow);
	if (slice.valid()) {
		ret = max((int)ret, f(x1, x2 + 1, y1, y2) + slice.gain());
	}
	slice = inter({x1, x2, y1 - 1, y1 - 1}, allow);
	if (slice.valid()) {
		ret = max((int)ret, f(x1, x2, y1 - 1, y2) + slice.gain());
	}
	slice = inter({x1, x2, y2 + 1, y2 + 1}, allow);
	if (slice.valid()) {
		ret = max((int)ret, f(x1, x2, y1, y2 + 1) + slice.gain());
	}
	return ret;
}
int main() {
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; ++i) {
		scanf("%s", G[i]);
		for (int j = 0; j < W; ++j) {
			S[i + 1][j + 1] = S[i + 1][j] + S[i][j + 1] - S[i][j] + (G[i][j] == 'o');
			if (G[i][j] == 'E') {
				ex = j + 1;
				ey = i + 1;
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = f(ex, ex, ey, ey);
	printf("%d\n", ans);
}
