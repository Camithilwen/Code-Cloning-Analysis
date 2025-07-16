#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
#define vpl vector<pl>
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005

int n,p[200005],r[200005];
ll d,a[200005],f[200005],g[200005],ans;

vector <pair<ll,pi>> s;

int Par(int nod){
	if(p[p[nod]]==p[nod]) return p[nod];
	else return p[nod]=Par(p[nod]);
}

void Unite(int x, int y){
	x=Par(x); y=Par(y);
	if(x==y) return;
	if(r[x]>r[y]) swap(x,y);
	if(r[x]==r[y]) r[y]++;
	p[x]=y;
}

void DC(int l, int r){
	if(l==r) return;
	int mid=(l+r)/2;
	DC(l,mid);
	DC(mid+1,r);
	int x=0,y=0;
	for(int i=l;i<=mid;i++){
		if(f[i]<f[x]) x=i;
	}
	for(int i=mid+1;i<=r;i++){
		if(g[i]<g[y]) y=i;
	}
	for(int i=l;i<=mid;i++){
		s.pb({f[i]+g[y],{i,y}});
	}
	for(int i=mid+1;i<=r;i++){
		s.pb({f[x]+g[i],{x,i}});
	}
}

int32_t main(){
	ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
#ifdef LOCAL_DEFINE
	ifstream cin("input.in");
#endif

	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		p[i]=i;
		f[i]=-d*i+a[i];
		g[i]=d*i+a[i];
	}
	f[0]=g[0]=LINF;
	DC(1,n);
	sort(s.begin(),s.end());
	for(pair<ll,pi> i : s){
		if(Par(i.y.x)==Par(i.y.y)) continue;
		Unite(i.y.x,i.y.y);
		ans+=i.x;
	}
	cout << ans;
	
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << " \n";
#endif
}
