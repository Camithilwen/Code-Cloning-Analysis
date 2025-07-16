#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define INF 200000009
class DSU{
public:
	int fa[200005];
	inline void init(){
		for (int i=0;i<200005;++i) fa[i]=i;
	}
	inline int f(int x){
		return fa[x]==x? x:fa[x]=f(fa[x]);
	}
	inline void u(int x,int y){
		x=f(x);y=f(y);
		if (x==y) return;
		fa[x]=y;
	}
	inline bool same(int x,int y){
		return (f(x)==f(y)); 
	} 
}dsu;

typedef pair<ll,pii> Edge;
vector<Edge> edges;
ll a[200005];ll d;
int n;
inline void solve(int l,int r){
	if (l==r) return;
	if (l==r-1){
		edges.pb(mp(a[l]+a[r]+d,mp(l,r)));
		return;
	}
	int m=(l+r)>>1;
	solve(l,m);solve(m+1,r);
	int bestl,bestr;
	ll mincostl=1e18;
	for (int i=l;i<=m;++i){
		if (a[i]-d*i<mincostl){
			mincostl=a[i]-d*i;bestl=i;
		}
	}
	ll mincostr=1e18;
	for (int i=m+1;i<=r;++i){
		if (a[i]+d*i<mincostr){
			mincostr=a[i]+d*i;bestr=i;
		}
	}
	for (int i=l;i<=m;++i){
		edges.pb(mp(mincostr+a[i]-d*i,mp(i,bestr)));
	}
	for (int i=m+1;i<=r;++i){
		edges.pb(mp(mincostl+a[i]+d*i,mp(bestl,i)));
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>d;
	for (int i=1;i<=n;++i) cin>>a[i];
	if (n==1){
		cout<<0<<endl;return 0;
	}
	solve(1,n);
	sort(edges.begin(),edges.end());// smaller to bigger
	reverse(edges.begin(),edges.end());// bigger to smaller
	dsu.init();
	ll ans=0;
	while(!edges.empty()){
		Edge E=edges.back();edges.pop_back();
		ll u=E.S.F,v=E.S.S,cost=E.F;
		if (dsu.same(u,v)) continue;
		dsu.u(u,v);
		ans+=cost;
	}
	cout<<ans;
	return 0; 
}