#include <bits/stdc++.h>
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;
 
#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)
 
typedef long long ll;
 
template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}
 
/*
const int N=,P=;
 
int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int gcd(int a,int b){ return !b?a:gcd(b,a%b); }
*/
 
const int N=5e5+50;
int n;
typedef pair<int,int> pii;
pii a[N],c[N];
ll ans;
ll L(int a,int b){ return max(b-a+1,0); }
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("d.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].fi,&a[i].sc);
	sort(a+1,a+n+1,[](pii a,pii b){return a.sc==b.sc?a.fi<b.fi:a.sc<b.sc; });
	sort(a+2,a+n+1,[](pii a,pii b){return a.fi==b.fi?a.sc<b.sc:a.fi<b.fi; });
	c[n]=a[n];
	dec(i,n-1,2){
		c[i].fi=max(a[i].fi,c[i+1].fi);
		c[i].sc=min(a[i].sc,c[i+1].sc);
	}
	//ans=L(c[2].fi,c[2].sc)+L(a[1].fi,a[1].sc);
	ll lmax=0;
	rep(i,2,n){
		ans=max(ans,L(c[i].fi,c[i].sc)+L(max(a[i-1].fi,a[1].fi),a[1].sc));
		//Pr("%d,%d---%d,%d\n",c[i].fi,c[i].sc,a[i-1].fi,a[1].sc);
		cmax(lmax,L(a[i].fi,a[i].sc));
	}
	ans=max(ans,lmax+L(max(a[n].fi,a[1].fi),a[1].sc));
	printf("%lld\n",ans);
	return 0;
}

