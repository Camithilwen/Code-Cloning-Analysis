#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<LL,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const LL INF=1e18;
int n,D,a[500010];
bool u[500010];
LL ans;
struct node{
	pa v[2][2]; //[in MST now];[use + -]
	pa t;
	node(){
		v[0][0]=v[0][1]=v[1][0]=v[1][1]=mp(INF,0);
		t=mp(INF,0);
	}
}T[800010];
void pushup(int rt){
	T[rt].t=min(T[rt<<1].t,T[rt<<1|1].t);
	T[rt].t=min(T[rt].t,mp(T[rt<<1].v[0][0].fi+T[rt<<1|1].v[1][1].fi,T[rt<<1].v[0][0].se));
	T[rt].t=min(T[rt].t,mp(T[rt<<1].v[1][0].fi+T[rt<<1|1].v[0][1].fi,T[rt<<1|1].v[0][1].se));
	T[rt].v[0][0]=min(T[rt<<1].v[0][0],T[rt<<1|1].v[0][0]);
	T[rt].v[0][1]=min(T[rt<<1].v[0][1],T[rt<<1|1].v[0][1]);
	T[rt].v[1][0]=min(T[rt<<1].v[1][0],T[rt<<1|1].v[1][0]);
	T[rt].v[1][1]=min(T[rt<<1].v[1][1],T[rt<<1|1].v[1][1]);
}
void build(int l,int r,int rt){
	if (l==r){
		T[rt].v[u[l]][0]=mp(a[l]-1ll*l*D,l);
		T[rt].v[u[l]][1]=mp(a[l]+1ll*l*D,l);
		T[rt].v[u[l]^1][0]=mp(INF,0);
		T[rt].v[u[l]^1][1]=mp(INF,0);
		return;
	}
	int m=l+r>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void upd(int l,int r,int rt,int x){
	if (l==r){
		T[rt].v[u[l]][0]=mp(a[l]-1ll*l*D,l);
		T[rt].v[u[l]][1]=mp(a[l]+1ll*l*D,l);
		T[rt].v[u[l]^1][0]=mp(INF,0);
		T[rt].v[u[l]^1][1]=mp(INF,0);
		return;
	}
	int m=l+r>>1;
	if (x<=m) upd(l,m,rt<<1,x);
	else upd(m+1,r,rt<<1|1,x);
	pushup(rt);
}
void prim(){
	build(1,n,1);
	u[1]=1;
	upd(1,n,1,1);
	FOR(rp,2,n){
		pa tmp=T[1].t;
		ans+=tmp.fi;
		u[tmp.se]=1;
		upd(1,n,1,tmp.se);
	}
}
int main(){
	cin>>n>>D;
	FOR(i,1,n) getint(a[i]);
	prim();
	printf("%lld\n",ans);
	return 0;
}
