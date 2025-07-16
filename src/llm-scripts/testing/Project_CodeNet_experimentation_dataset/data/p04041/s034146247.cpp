//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
//#define double long double



template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

const int MOD = 1e9 + 7;
int n, x, y, z, l, ng;
ll dp[41][1 << 16], ans;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> x >> y >> z;
	l = x + y + z - 1;
	int m = (1 << l) - 1;
	ng = (1 << l) | (1 << (l - x)) | (1 << (l - x - y));
	dp[0][0] = 1;
	REP(i, n) {
		FOR(a, 1, 11) {
			REP(s, 1 << l) {
				int t = (s << a) | (1 << (a - 1));
				if ((ng & t) != ng)dp[i + 1][t & m] = (dp[i + 1][t & m] + dp[i][s]) % MOD;

			}
		}
	}
	ans = 1;
	REP(i, n)ans = ans * 10 % MOD;
	REP(s, 1 << l) {
		ans += MOD - dp[n][s]; ans %= MOD;
	}
	print(ans);
}
