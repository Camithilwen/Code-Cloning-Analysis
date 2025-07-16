#include "bits/stdc++.h"
#include <sys/timeb.h>
#include <fstream>

using namespace std;

#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define INF 1050000000
#define INFL 9e18
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295

typedef long long ll;
typedef pair<int, int> Pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<Pi> > vvPi;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi> > pqlP;
struct Edge {
	int from, to, cost;
	bool operator<(Edge e) {
		return cost < e.cost;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
template <class T>
using vec = vector<T>;
template<class T>
using pql = priority_queue<T, vector<T>, greater<T>>;
string debug_show(Pi a) {
	return "(" + to_string(a.first) + "," + to_string(a.second) + ")";
}

template<class T>
struct augEdge {
	T from, to;
	int cost;
	bool operator<(augEdge e) { return cost < e.cost; }
	bool operator>(augEdge e) { return cost > e.cost; }
};
template<class T>
using augGraph = vector<augEdge<T>>;

class Lowlink {
public:
	vi ord, low;
	vb vis;
	vi articulation;
	vPi bridge;

	Lowlink(const Graph &G) {
		ord = vi(G.size());
		low = vi(G.size());
		vis = vb(G.size(), false);
		int k = 0;
		for (int i = 0; i < G.size(); i++) {
			if (!vis[i]) dfs(G, i, -1, k);
		}
	}

	void dfs(const Graph &G, int v, int p, int &k)
	{
		vis[v] = true;

		ord[v] = k++;
		low[v] = ord[v];

		bool isArticulation = false;
		int ct = 0;

		for (int i = 0; i < G[v].size(); i++) {
			if (!vis[G[v][i].to]) {
				ct++;
				dfs(G, G[v][i].to, v, k);
				low[v] = min(low[v], low[G[v][i].to]);
				if (p != -1 && ord[v] <= low[G[v][i].to]) isArticulation = true;
				if (ord[v] < low[G[v][i].to]) bridge.push_back(make_pair(min(v, G[v][i].to), max(v, G[v][i].to)));
			}
			else if (G[v][i].to != p) {
				low[v] = min(low[v], ord[G[v][i].to]);
			}
		}

		if (p == -1 && ct > 1) isArticulation = true;
		if (isArticulation) articulation.push_back(v);
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	Graph G(N);
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		//a--; b--;
		G[a].push_back(Edge{ a,b,1 });
		G[b].push_back(Edge{ b,a,1 });
	}

	Lowlink lowlink(G);
	sort(all(lowlink.articulation));

	for (auto a : lowlink.articulation)cout << a << endl;

	return 0;
}