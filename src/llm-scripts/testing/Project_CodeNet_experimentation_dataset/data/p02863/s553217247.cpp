#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> PI;
typedef pair<int, int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

int n, T;
P a[3300];
int dp[3300][3300];

void solve()
{
	cin >> n >> T;
	REP(i, n) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int t = 0; t < T; t++) {
			dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
			if (t - a[i].first >= 0) dp[i + 1][t] = max(dp[i + 1][t], dp[i][t - a[i].first] + a[i].second);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i][T - 1] + a[i].second);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
