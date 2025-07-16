#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
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


// ????????°???????????¨???
void add_edge(Graph& graph, int u, int v, int cost = 0){
  graph[u].push_back(Edge(v,cost));
  graph[v].push_back(Edge(u,cost));
}

int prim(const Graph& G){
  const int V = G.size();
  int res = 0;
  vector<bool> visited(V, false);
  priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

  pq.push(Edge(0,0));
  for(int i=0;i<V;++i){
	Edge edge = pq.top(); pq.pop();
	int v = edge.to;
	if(visited[v]){
	  --i;
	  continue;
	}
	visited[v] = true;
	res += edge.cost;

	for(const auto& e:G[v]){
	  pq.push(e);
	}
  }

  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E; cin >> V >> E;
  Graph G(V);
  REP(i,E){
	int a, b, c; cin >> a >> b >> c;
	add_edge(G, a, b, c);
  }

  cout << prim(G) << endl;

  return 0;
}