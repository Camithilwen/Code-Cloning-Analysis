#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<=int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define per1(i,n) for(int i=int(n);i>0;i--)
#define all(c) c.begin(),c.end()
#define si(x) int(x.size())
#define pb emplace_back
#define fs first
#define sc second
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<class T,class U> void chmax(T& x, U y){if(x<y) x=y;}
template<class T,class U> void chmin(T& x, U y){if(y<x) x=y;}
template<class T> void mkuni(V<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
void dmpr(ostream& os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ~ ";
	dmpr(os,args...);
}
#define shows(...) cerr << "LINE" << __LINE__ << " : ";dmpr(cerr,##__VA_ARGS__)
#define dump(x) cerr << "LINE" << __LINE__ << " : " << #x << " = {";  \
	for(auto v: x) cerr << v << ","; cerr << "}" << endl;
#else
#define show(x) void(0)
#define dump(x) void(0)
#define shows(...) void(0)
#endif
struct UnionFind{
	vector<int> par;
	UnionFind(int N){
		par.assign(N,0);
		rep(i,N) par[i]=i;
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		par[y]=x;
	}
};
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);

	int N; cin >> N;
	V<int> x(N),y(N);
	rep(i,N) cin >> x[i] >> y[i];
	VV<ll> es;
	rep(_,2){
		V<int> idx(N); iota(all(idx),0);
		sort(all(idx),[&](int l,int r){return x[l]<x[r];});
		rep(i,N-1){
			int a = idx[i], b = idx[i+1];
			es.push_back({x[b]-x[a],a,b});
		}
		rep(i,N) swap(x[i],y[i]);
	}
	sort(all(es));
	UnionFind UF(N);
	ll ans=0;
	for(auto e: es){
		if(!UF.same(e[1],e[2])){
			UF.unite(e[1],e[2]);
			ans += e[0];
		}
	}
	cout << ans << endl;
}
