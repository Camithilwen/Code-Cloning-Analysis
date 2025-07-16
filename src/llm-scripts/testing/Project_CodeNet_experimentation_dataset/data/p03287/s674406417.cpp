#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll N, M;
ll A[100010];

int main(int argc, char **argv)
{
	cin >> N >> M;
	REP(i, N) cin >> A[i];
	A[0] %= M;
	REP(i, N-1)
		(A[i+1] += A[i]) %= M;

	map<ll, ll> m;
	REP(i, N)
		++m[A[i]];

	ll res{0};
	for (auto &p : m)
	{
		if (p.first == 0)
			res += p.second;
		res += p.second * (p.second-1) / 2;
	}

	std::cout << res << std::endl;
}
