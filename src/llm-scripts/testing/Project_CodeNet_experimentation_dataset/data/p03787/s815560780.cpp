#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

vector<vi> e;
int v[100000];
void rec(int c, int col, bool &bi, int &x, int &y){
	if(col > 0) x++; else y++;
	v[c] = col;
	for(int i : e[c]){
		if(v[i]){
			if(v[i] == col) bi = 0;
		}
		else rec(i, -col, bi, x, y);
	}
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n, m; cin >> n >> m;
	e.resize(n);
	rep(i, m){
		int a, b; cin >> a >> b; a--; b--;
		e[a].pb(b);
		e[b].pb(a);
	}
	vector<pi> bigraph;
	vi graph;
	int point = 0;
	
	rep(i, n) if(!v[i]){
		bool bi = 1;
		int x = 0, y = 0;
		rec(i, 1, bi, x, y);
		if(bi){
			if(x + y == 1) point++;
			else bigraph.emplace_back(x, y);
		}
		else graph.pb(x + y);
	}
	//dbg(bigraph);dbg(graph);dbg(point);
	
	ll ans = 0;
	for(pi a : bigraph){
		/*
		for(pi b : bigraph){
			ans += 2;
		}
		for(int b : graph){
			ans++;
		}*/
		ans += bigraph.size() * 2;
		ans += graph.size();
		ans += (ll)point * (a.first + a.second);
	}
	dbg(ans);
	for(int a : graph){
		/*
		for(pi b : bigraph){
			ans++;
		}
		for(int b : graph){
			ans++;
		}*/
		ans += bigraph.size();
		ans += graph.size();
		ans += (ll)point * a;
	}
	dbg(ans);
	{
		for(pi b : bigraph){
			ans += (ll)point * (b.first + b.second);
		}
		for(int b : graph){
			ans += (ll)point * b;
		}
		ans += (ll)point * point;
	}
	cout << ans << endl;
	return 0;
}