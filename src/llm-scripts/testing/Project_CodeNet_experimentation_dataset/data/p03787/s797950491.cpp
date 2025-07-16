#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define rng(i,l,r) for(int i=int(l);i<int(r);i++)
#define rep(i,r) rng(i,0,r)
#define rrng(i,l,r) for(int i=int(r)-1;i>=int(l);i--)
#define rrep(i,r) rrng(i,0,r)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#define inf INT_MAX/2-100
#define infl LLONG_MAX/3
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<' '<<#x<<' '<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u>bool chmax(t&a,u b){if(a<b)a=b;return a<b;}
template<class t,class u>bool chmin(t&a,u b){if(b<a)a=b;return b<a;}
 
template<class t>using vc=vector<t>;
template<class t>using vvc=vector<vector<t>>;
 
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vi=vc<int>;
using vl=vc<ll>;
 
 
ll readl(void){
	ll x;
	cin>>x;
	return x;
}
int readi(void){
	int x;
	cin>>x;
	return x;
}
 
string readstr(){
	string s;
	cin>>s;
	return s;
}
vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=readi(),v[i]+=off;
	return v;
}
 
vl readvl(int n,int off=0){
	vl v(n);
	rep(i,n)v[i]=readl(),v[i]+=off;
	return v;
}
 
template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)cout<<"\n";
	if(suc==2)cout<<" ";
}
 
template<class t>
void print(const vc<t>&v,int suc=1){
	rep(i,si(v))print(v[i],i==int(si(v))-1?1:suc);
}
 
template<class t>
bool inc(t a,t b,t c){
	return !(c<b||b<a);
}
 
template<class t>
void compress(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}
 
template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}
 
template<class t>
struct Compress{
	vc<t>v;
	Compress()=default;
	Compress(const vc<t>&x){
		add(x);
	}
	Compress(const initializer_list<vc<t> >&x){
		for(auto &p:x)add(p);
	}
	void add(const t&x){
		v.eb(x);
	}
	void add(const vc<t>&x){
		copy(all(x),back_inserter(v));
	}
	void build(){
		compress(v);
	}
	int get(const t&x)const{
		return lwb(v,x);
	}
	vc<t>get(const vc<t>&x)const{
		vc<t>res(x);
		for(auto &p:res)p=get(p);
		return res;
	}
	const t &operator[](int x)const{
		return v[x];
	}
	int size(){
		return v.size();
	}
};
void Yes(bool ex=true){
	cout<<"Yes\n";
	if(ex)exit(0);
}
void YES(bool ex=true){
	cout<<"YES\n";
	if(ex)exit(0);
}
void No(bool ex=true){
	cout<<"No\n";
	if(ex)exit(0);
}
void NO(bool ex=true){
	cout<<"NO\n";
	if(ex)exit(0);
}
void orYes(bool x,bool ex=true){
	if(x)Yes(ex);
	else No(ex);
}
void orYES(bool x,bool ex=true){
	if(x)YES(ex);
	else NO(ex);
}
void Possible(bool ex=true){
	cout<<"Possible\n";
	if(ex)exit(0);
}
void POSSIBLE(bool ex=true){
	cout<<"POSSIBLE\n";
	if(ex)exit(0);
}
void Impossible(bool ex=true){
	cout<<"Impossible\n";
	if(ex)exit(0);
}
void IMPOSSIBLE(bool ex=true){
	cout<<"IMPOSSIBLE\n";
	if(ex)exit(0);
}
void orPossible(bool x,bool ex=true){
	if(x)Possible(ex);
	else Impossible(ex);
}
void orPOSSIBLE(bool x,bool ex=true){
	if(x)POSSIBLE(ex);
	else IMPOSSIBLE(ex);
}
ll n,m,vis[100005],ans,e,o,s,r;
vl g[100005];
bool dfs(int v,int k){
	bool res=true;
	vis[v]=k;
	s++;
	for(auto &i:g[v]){
		if(vis[i]==0){
			res&=dfs(i,k*-1);
		}else if(vis[i]==k){
			res=false;
		}
	}
	return res;
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	rep(i,m){
		ll a,b;
		cin>>a>>b;
		g[--a].pb(--b);
		g[b].pb(a);
	}
	fill(vis,vis+n,0);
	r=n;
	rep(i,n){
		if(vis[i]==0){
			s=0;
			bool bd=dfs(i,1);
			if(s==1)ans+=r*2LL-1LL,r--;
			else if(bd)e++;
			else o++;
		}
	}
	ans+=o*o;
	ans+=e*o*2LL;
	ans+=e*e*2LL;
	print(ans);
}