
#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A & a, const B & b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A & a, const B & b) { a = max(a, (A)b); };

void factorize(ll X, vector<pair<ll,ll>>& ret) {
	for (ll i = 2; i * i <= X; ++i) {
		if (X % i != 0) continue;
		ret.push_back(pair<ll, ll>{i, 0});
		while (X % i == 0) {
			X /= i;
			ret.back().second++;
		}
	}
	if (X != 1) ret.push_back(pair<ll, ll>{X, 1});
}

int main() {
	ll mod = 1e9 + 7;
	ll N, M;
	cin >> N >> M;
	vector<vector<ll>> dp(N+1);
	vector<pair<ll, ll>> P;
	factorize(M, P);
	ll maxn = 0;
	for (const auto& p : P) maxs(maxn, p.second);
	REP(i, 0, N + 1) dp[i].resize(maxn + 1, 0);
	REP(i, 0, maxn + 1)dp[1][i] = 1;
	REP(i, 0, N + 1)dp[i][1] = i;
	REP(i, 2, N + 1) REP(j, 2, maxn + 1) dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
	ll ans = 1;
	for (const auto& p : P) ans = ans * dp[N][p.second] % mod;
	PRI(ans);
	return 0;
}