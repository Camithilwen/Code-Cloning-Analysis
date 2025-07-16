#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <istream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <climits>
using namespace std;

typedef ostringstream OSS;
typedef istringstream ISS;

typedef vector<int> VI;
typedef vector< VI > VVI;

typedef long long LL;

typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define X first
#define Y second

const LL MOD = 1000000007;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

const int INF = INT_MAX;

PII S;
PII T;
int W, H;
int ans;

void move(VVI ts, PII p, int n) {
	if (++n > 10) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int x = p.X;
		int y = p.Y;
		bool first = true;

		while (true) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= W || ny >= H) {
				break;
			}
			if (first && ts[ny][nx] == 1) {
				break;
			}
			first = false;

			if (ts[ny][nx] == 3) {
				ans = min(ans, n);
				break;
			}

			if (ts[ny][nx] == 1) {
				VVI nts(ts);
				nts[ny][nx] = 0;
				move(nts, make_pair(x, y), n);
				break;
			}

			x = nx;
			y = ny;
		}
	}
}

int main(void) {
	while (cin >> W >> H, W) {
		VVI ts(H, VI(W));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> ts[i][j];
				if (ts[i][j] == 2) {
					S = make_pair(j, i);
				}
				if (ts[i][j] == 3) {
					T = make_pair(j, i);
				}
			}
		}

		VI pattern(10, 0);
		ans = INF;

		move(ts, S, 0);

		cout << (ans == INF ? -1 : ans) << endl;
	}

	return 0;
}