#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
// #define MOD 998244353
#define VL vector<ll>

vector<ll> dx = {-1, 1, 0,  0, -1, -1,  1, 1};
vector<ll> dy = { 0, 0, 1, -1, -1,  1, -1, 1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }



template< typename T >
struct edge {
	int src, to;
	T cost;

	edge(int to, T cost) : src(-1), to(to), cost(cost) {}

	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

	edge &operator=(const int &x) {
		to = x;
		return *this;
	}

	operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
/*
WeightedGraph<ll> g(V);
g[a].emplace_back(b, c);
*/
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


template< typename T >
void dijkstra(WeightedGraph< T > &g, vector< T > &dist, vector< T > &prev, vector< T > &num, int s) {
	T N = g.size();
	dist.resize(N, INF);
	prev.resize(N, -1); // 初期化
	num.resize(N, 0);
	using Pi = pair< T, int >;
	priority_queue< Pi, vector< Pi >, greater< Pi > > que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while(!que.empty()) {
	T cost;
	int idx;
	tie(cost, idx) = que.top();
	que.pop();
	if(dist[idx] < cost) continue;
	for(auto &e : g[idx]) {
		auto next_cost = cost + e.cost;
		if(dist[e.to] < next_cost) continue;
		if (dist[e.to] == next_cost) {
			num[e.to] += num[idx];
			num[e.to] %= MOD;
			continue;
		}
		dist[e.to] = next_cost;
		prev[e.to] = idx; // 頂点 v を通って e.to にたどり着いた
		num[e.to] = num[idx];
		que.emplace(dist[e.to], e.to);
	}
	}
	return;
}

/* get_path(prev, t)
	入力：dijkstra で得た prev, ゴール t
	出力： t への最短路のパス
*/
template< typename T >
vector<T> get_path(const vector<T> &prev, T t) {
	vector<T> path;
	for (T cur = t; cur != -1; cur = prev[cur]) {
		path.push_back(cur);
	}
	reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
	return path;
}

int main()
{
	ll N, u, v;
	cin >> N >> u >> v;
	u--; v--;
	if (N == 2) {
		PRINT(0);
		return 0;
	}
	WeightedGraph<ll> G(N);
	REP(i, N-1) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		G[a].emplace_back(b,1);
		G[b].emplace_back(a,1);
	}
	vector<ll> dist1, prev1, num1;
	dijkstra(G,dist1,prev1,num1,u);
	vector<ll> dist2, prev2, num2;
	dijkstra(G,dist2,prev2,num2,v);
	// REP(i, N) cout << dist1[i] << " ";
	// cout << endl;
	// REP(i, N) cout << dist2[i] << " ";
	// cout << endl;
	ll ma = 0;
	REP(i, N) {
		if (dist1[i] < dist2[i]) {
			ma = max(ma, dist2[i]);
		}
	}
	PRINT(ma-1);
	return 0;
}
