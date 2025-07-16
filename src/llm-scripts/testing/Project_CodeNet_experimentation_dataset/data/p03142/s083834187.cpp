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
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

vector<ll> seen, deg, par;
vector<vector<ll>> G;

void dfs(ll v, ll pav)
{
	seen[v] = true;
	par[v] = pav+1;

	for (auto &nv : G[v])
		--deg[nv];

	for (auto &nv : G[v])
	{
		if (!deg[nv] && !seen[nv])
			dfs(nv, v);
	}
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N, M; cin >> N >> M;
	G.resize(N);
	par.resize(N);
	deg.assign(N, 0);
	seen.assign(N, false);
	REP(i, N-1+M)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		deg[b]++;
	}

	ll root;
	REP(i, N)
		if (!deg[i])
			root = i;

	dfs(root, -1);

	REP(i, N)
		std::cout << par[i] << std::endl;
	return 0;
}
