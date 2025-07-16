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
//#include<unordered_map>
//#include<unordered_set>
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
typedef pair<Int, Int> P; 
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

Int dp[201][1000001];

void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> S(N);
	for (int i = 0; i < n; i++) cin >> S[i];
	sort(S.rbegin(), S.rend());

	dp[0][x] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 100000; j++) {
			dp[i + 1][j%S[i]] = (dp[i + 1][j%S[i]] + dp[i][j]) % MOD;
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (n - i - 1)) % MOD;
		}
	}

	Int ans = 0;
	for (int j = 0; j <= 100000; j++) ans = (ans + (j*dp[n][j]%MOD)) % MOD;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
