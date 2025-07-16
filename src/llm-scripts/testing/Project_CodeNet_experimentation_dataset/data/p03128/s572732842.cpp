#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(int i = 0; i < (n); i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define REP(i, vec) for(auto i = vec.begin(); i != vec.end(); ++i)

const int mod = 1000000007;
const int inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T> inline T LCM(T a, T b) { return (a + (b - 1)) / b; }

int round_int(int a, int b) { return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

constexpr array<int, 10> cost = { -1,2,5,5,4,5,6,3,7,6 };

int calc_cost(deque<int> d) {
	int res = 0;
	while (!d.empty()) {
		int v = d.front(); d.pop_front();
		res += cost[v];
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;

	vi a(m);
	rep(i, m) cin >> a[i];

	vector<vector<deque<int>>> dp(n + 1, vector<deque<int>>(m));

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < m; ++j) {
			int c = cost[a[j]];
			//cout << i << " " << j << endl;
			if (i - c >= 0 && calc_cost(dp[i - c][j]) + c == i) {
				deque<int> pre = dp[i - c][j];
				if (pre.size() == 0) pre.push_back(a[j]);
				else if (pre.front() > a[j]) pre.push_back(a[j]);
				else pre.push_front(a[j]);
				dp[i][j] = pre;
			}

			if (j != 0) {
				deque<int> pre = dp[i][j - 1];

				if (pre.size() < dp[i][j].size()) continue;
				else if (pre.size() > dp[i][j].size()) dp[i][j] = pre;
				else if (pre.size() == dp[i][j].size()) {
					if (pre.size() == 0) continue;

					deque<int> tmp1 = pre, tmp2 = dp[i][j];
					for (int k = 0; k < pre.size(); ++k) {
						int l = tmp1.front(), r = tmp2.front();
						tmp1.pop_front(), tmp2.pop_front();

						if (l > r) {
							dp[i][j] = pre;
							break;
						}
						else if (l < r) {
							break;
						}
					}
				}
			}
		}
	}

	int mx = dp[n][m - 1].size();
	rep(i, mx) {
		int v = dp[n][m - 1].front(); dp[n][m - 1].pop_front();
		cout << v;
	}
}