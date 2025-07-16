#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<limits>
#include<complex>
#include<array>
#include<numeric>
#include<functional>

using namespace std;
#define ll long long
#define ull unsigned long long
#define rrep(i,m,n) for(ll (i)=(ll)(m);(i)>=(ll)(n);(i)--)
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
constexpr long double m_pi = 3.1415926535897932L;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 61;
constexpr long double EPS = 1e-10;
template<typename T> using vector2 = vector<vector<T>>;
template<typename T> using vector3 = vector<vector2<T>>;
typedef vector<ll> Array;

ll dp[65][101010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	Array x(n);
	REP(i, n)cin >> x[i];
	ll m, k;
	cin >> m >> k;
	Array a(m);
	REP(i, m)cin >> a[i], a[i]--;
	Array d(n - 1);
	REP(i, n - 1)d[i] = x[i + 1] - x[i];
	Array p(n - 1);
	REP(i, n - 1)p[i] = i;
	REP(i, m)swap(p[a[i]], p[a[i] - 1]);
	REP(i, n - 1) dp[0][i] = p[i];
	REP(i, 63)REP(j, n - 1)dp[i + 1][j] = dp[i][dp[i][j]];
	cout << x[0] << "\n";
	REP(i, n - 1) {
		ll now = i;
		REP(j, 61)if (k & (1LL << j))now = dp[j][now];
		x[i + 1] = x[i] + d[now];
		cout << x[i + 1] << "\n";
	}

	return 0;
}