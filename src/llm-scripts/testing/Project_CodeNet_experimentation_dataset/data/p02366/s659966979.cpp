#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

struct node {int to,cost; };

typedef vector< vector<node> > G;

inline void add_edge(G& g,int from,int to,int cost=1){
	node in; in.to=to; in.cost=cost;
	g[from].pb(in);
}

inline void add_both_edge(G& g,int from,int to,int cost=1){	
	add_edge(g,from,to,cost);
	add_edge(g,to,from,cost);
}

void dfs(const G& g,int cur,int prev,int &k,vi& order, vi& low,vi& parent) {
	order[cur]=k++;
	low[cur]=order[cur];

	rep(i,g[cur].size()){
		int to=g[cur][i].to;
		if(order[to]==-1){
			parent[to]=cur;
			dfs(g,to,cur,k,order,low,parent);
			low[cur]=min(low[cur],low[to]);
		}else if(to!=prev)
			low[cur]=min(low[cur],order[to]);
	}
	return;
}

void Lowlink(const G& g, vi& order,vi& low,vi& parent) {
	int v=g.size();
	order.assign(v,-1);
	low.resize(v);
	parent.resize(v);
	int k=0;
	parent[0]=-1;
	dfs(g,0,-1,k,order,low,parent);
	return ;
}

int main(void){
	int n,m;
	cin >> n >> m;
	G graph(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		add_both_edge(graph,a,b);
	}
	vi order,low,parent;
	Lowlink(graph,order,low,parent);

	rep(i,n){
		if(i){
			bool ok=false;
			rep(j,graph[i].size()){
				int to=graph[i][j].to;
				if(i==parent[to]&&order[i]<=low[to])
					ok=true;
			}
			if(ok) cout << i << endl;
		}else{
			int d=0;
			rep(j,n) if(parent[j]==0) d++;
			if(d>=2) cout << i << endl;
		}
	}
	return 0;
}