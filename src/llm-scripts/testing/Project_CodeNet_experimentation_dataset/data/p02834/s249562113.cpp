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
//#define DEBUG(x) ;

ll N, u, v; 
vector<vector<ll>> G;
vector<ll> du, dv;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> u >> v;
	--u, --v;

	G.resize(N);
	du.assign(N, -1);
	dv.assign(N, -1);

	REP(i, N-1)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	queue<ll> que;
	que.push(v);
	dv[v] = 0;

	while (que.size())
	{
		ll now = que.front();
		que.pop();

		for (auto &nv : G[now])
		{
			if (dv[nv] != -1) continue;
			dv[nv] = dv[now] + 1;
			que.push(nv);
		}
	}

	que.push(u);
	du[u] = 0;

	while (que.size())
	{
		ll now = que.front();
		que.pop();

		for (auto &nv : G[now])
		{
			if (du[nv] != -1) continue;
			du[nv] = du[now] + 1;
			que.push(nv);
		}
	}

	ll res{0};
	REP(n, N)
	{
		if (du[n] < dv[n])
		{
			res = max(res, dv[n] - 1);
		}
	}

	std::cout << res<< std::endl;	
	return 0;
}
