#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef vector<int> vi;
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define SZ(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
#define repe(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
const int MAXN = 5050;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXN];
vector<pii> prt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	rep (i, 1, n) {
		int h, p;
		cin >> h >> p;
		prt.emplace_back(h, p);
	}
	sort(all(prt), [&] (pii a, pii b) {
		return a.fst + a.sed < b.fst + b.sed;
	});
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	auto chkMin = [&] (int & a, int b) {
		a = ~a ? min(a, b) : b;
	};
	int res = 0;
	rep (i, 1, n) {
		int h = prt[i - 1].fst;
		int p = prt[i - 1].sed;
		rep (j, 0, i - 1) if (~dp[i - 1][j]) {
			chkMin(dp[i][j], dp[i - 1][j]);
			if (dp[i - 1][j] <= h) {
				res = max(res, j + 1);
				chkMin(dp[i][j + 1], dp[i - 1][j] + p);
			}
		}
	}
	cout << res << endl;
	return 0;
}