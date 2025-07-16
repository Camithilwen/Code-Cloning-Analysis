#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;
struct Edge{
  int to, cost;

  Edge(int t, int c = 0): to(t), cost(c)
  {}
  bool operator>(const Edge& rhs) const{
	return cost > rhs.cost;
  }
  bool operator<(const Edge& rhs) const{
	return cost < rhs.cost;
  }

};
using Graph =  vector< vector<Edge> >;

void add_edge(Graph& graph, int u, int v, int cost = 0){
  graph[u].push_back(Edge(v,cost));
  graph[v].push_back(Edge(u,cost));
}

void lowlink(int u, int p, int& num, const Graph& G, VI& ord, VI& low,
			 VI& art, vector<pair<int,int>>& brd){
  ord[u] = low[u] = num++;
  int chd_num = 0, chd_low_mx = -1;

  for(unsigned int i=0;i<G[u].size();++i){
	auto& e =  G[u][i];
	int to = e.to;
	if(to == p) continue;
	if(ord[to] < 0){
	  lowlink(to, u, num, G, ord, low, art, brd);
	  low[u] = min(low[u], low[to]);
	  if(ord[u] < low[to]){
		brd.push_back(MP(u, i));
	  }
	  ++chd_num;
	  chd_low_mx = max(chd_low_mx, low[to]);
	}
	else{
	  low[u] = min(low[u], ord[to]);
	}
  }

  if(p == -1){
	if(chd_num > 1)
	  art.push_back(u);
  }
  else{
	if(ord[u] <= chd_low_mx)
	  art.push_back(u);
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;
  Graph G(V);
  REP(i,E){
	int u, v;
	cin >> u >> v;
	add_edge(G, u, v);
  }

  int num = 0;
  VI ord(V, -1);
  VI low(V, -1);
  vector<PII> brd;
  VI art;
  lowlink(0, -1, num, G, ord, low, art, brd);
  SORT(art);
  for(int v: art) cout << v << endl;

  return 0;
}

