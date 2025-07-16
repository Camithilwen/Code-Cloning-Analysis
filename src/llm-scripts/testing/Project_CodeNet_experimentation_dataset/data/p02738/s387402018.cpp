#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

ll dp[6010][6010];

int main() {
	int N; ll M;
	cin >> N >> M;
	int n = N * 3;

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (i >= 3) {
			for (int j = 0; j <= n; ++j) {
				(dp[i][j+1] += dp[i-3][j] * (i-1) % M * (i-2)) %= M;
			}
		}
		if (i >= 2) {
			for (int j = 0; j <= n; ++j) {
				(dp[i][j+1] += dp[i-2][j] * (i-1)) %= M;
			}
		}
		for (int j = 0; j <= n; ++j) {
			(dp[i][j] += dp[i-1][j]) %= M;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= N; ++i) {
		ans = (ans + dp[n][i]) % M;
	}
	cout << ans << endl;
	return 0;
}