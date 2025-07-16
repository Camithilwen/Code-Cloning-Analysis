#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll N, M, Q, sum[510][510], lr[510][510];

int main(int argc, char **argv)
{
	cin >> N >> M >> Q;
	REP(i, M)
	{
		ll l, r; cin >> l >> r;
		--l, --r;
		++lr[l][r];
	}

	REP(i, N)REP(j, N)
	{
		sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + lr[i][j];
	}

	REP(_, Q)
	{
		ll l, r; cin >> l >> r;
		--l, --r;
		std::cout << sum[r+1][r+1] - sum[r+1][l] - sum[l][r+1] + sum[l][l] << std::endl;
	}
}
