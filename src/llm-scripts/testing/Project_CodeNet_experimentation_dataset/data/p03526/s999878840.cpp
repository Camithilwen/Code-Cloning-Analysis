#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define se second
#define fi first

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> matrix;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

inline int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x;}
inline int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x;}
inline int mul(int x, int y) { return ((x % mod) * (y % mod)) % mod;}
inline int power(int a, int b) {
	int x = 1;
	while (b) {
		if (b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a) { return power(a, mod - 2);}

const int N = 5005;
int n, dp[N][N];
pii a[N];

bool cmp(pii one, pii two) {
	return (one.fi + one.se < two.fi + two.se);
}

#undef int
int main() {
#define int long long int
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	clock_t start = clock();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a + 1, a + n + 1, cmp);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = inf;
		}
	}

	dp[1][1] = a[1].se;
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[i - 1][j - 1] > a[i].fi) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + a[i].se);
				ans = max(ans, j);
			}
		}
	}


	cout << ans << endl;

	clock_t end = clock();
	cerr << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

	return 0;
}