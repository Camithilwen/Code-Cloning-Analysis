#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os << "[ "; 
	for(auto v:V)os << v << " "; return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){ os << "{ "; 
	for(auto s:S) os<<s<<" ";  return os<<"}"; 
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os<<"("<<P.first<<","<< P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
	os<<"{ ";for(auto m:M)os<<"("<<m.F<<":"<<m.S<<")";
	return os<<"}";
}
#define cerr cout
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define For(i,n) for(int i=0;i<(int)n;++i)
#define Rev(i,n) for(int i=(int)n-1;i>=0;--i)
#define Rep(i,n) for(int i=1;i<=(int)n;++i)
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpii;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int N = 1e6 + 100;
const int INF = 1e9;

int U[N] , V[N] , C[N];
int n , m;


vpii G[N];

int dis[N];


int main(){
	fio; cout<<fixed<<setprecision(25);	
	cin >> n >> m;

	map<pii , int> exist;
	int idx = n+1 , u , v , c;
	for(int i = 1;i <= m;++i){
		cin >> u >> v >> c;
		if(exist.find(mp(u , c)) == exist.end()){
			exist[mp(u , c)] = idx++;
		}
		if(exist.find(mp(v , c)) == exist.end()){
			exist[mp(v , c)] = idx++;
		}
		G[u].pb(mp(exist[mp(u , c)] , 1));
		G[exist[mp(u , c)]].pb(mp(u , 0));
		G[v].pb(mp(exist[mp(v , c)] , 1));
		G[exist[mp(v , c)]].pb(mp(v , 0));
		G[exist[mp(u , c)]].pb(mp(exist[mp(v , c)] , 0));
		G[exist[mp(v , c)]].pb(mp(exist[mp(u , c)] , 0));
	}
	for(int i =1 ;i < idx ; ++i){
		dis[i] = INF;
	}
	deque<pii> Q;
	// priority_queue<pair<pii, int> , vector<pair<pii,int> > , greater<pair<pii,int> > >Q;
	// Q.push(mp(mp(0 , -1) , 1));
	Q.pb(mp(0 , 1));
	dis[1] = 0;
	//it.F is distance
	//it.S is vertex
	while(Q.size() > 0){
		auto it = Q.front();
		// trace(it);
		if(it.S == n){
			cout << it.F << endl;
			return 0;
		}
		Q.pop_front();
		for(auto e : G[it.S]){
			int w = e.S + it.F;
			if(dis[e.F] > w){
				dis[e.F] = w;
				if(e.S == 1){
					Q.pb(mp(dis[e.F] , e.F));
				}
				else{
					Q.push_front(mp(dis[e.F] , e.F));
				}
			}
		}
	} 	
	cout << -1 << endl;








	return 0;
}
