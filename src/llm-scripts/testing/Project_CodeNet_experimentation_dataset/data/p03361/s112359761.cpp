#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;


string s[55];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int h, w; cin >> h >> w;
	rep(i, 0, h) cin >> s[i];


	rep(i, 0, h) rep(j, 0, w) {
		if (s[i][j] == '.') continue;
		bool ok = false;
		rep(k, 0, 4) {
			int nx = j + dx[k];
			int ny = i + dy[k];
			if (0 <= nx && nx < w && 0 <= ny && ny < h) {
				if (s[ny][nx] == '#') ok = true;
			}
		}
		if (!ok) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";

	return 0;
}