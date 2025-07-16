#include<bits/stdc++.h>
#define reg register int
#define il inline
#define fi first
#define se second
#define mk(a,b) make_pair(a,b)
#define numb (ch^'0')
#define pb push_back
#define solid const auto &
#define enter cout<<endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;
template<class T>il void rd(T &x){
    char ch;x=0;bool fl=false;while(!isdigit(ch=getchar()))(ch=='-')&&(fl=true);
    for(x=numb;isdigit(ch=getchar());x=x*10+numb);(fl==true)&&(x=-x);}
template<class T>il void output(T x){if(x/10)output(x/10);putchar(x%10+'0');}
template<class T>il void ot(T x){if(x<0) putchar('-'),x=-x;output(x);putchar(' ');}
template<class T>il void prt(T a[],int st,int nd){for(reg i=st;i<=nd;++i) ot(a[i]);putchar('\n');}
namespace Modulo{
const int mod=998244353;
il int ad(int x,int y){return x+y>=mod?x+y-mod:x+y;}
il int sub(int x,int y){return ad(x,mod-y);}
il int mul(int x,int y){return (ll)x*y%mod;}
il void inc(int &x,int y){x=ad(x,y);}
il void inc2(int &x,int y){x=mul(x,y);}
il int qm(int x,int y=mod-2){int ret=1;while(y){if(y&1) ret=mul(x,ret);x=mul(x,x);y>>=1;}return ret;}
template<class ...Args>il int ad(const int a,const int b,const Args &...args) {return ad(ad(a,b),args...);}
template<class ...Args>il int mul(const int a,const int b,const Args &...args) {return mul(mul(a,b),args...);}
}
//using namespace Modulo;
namespace Miracle{
const int N=2e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,q,A,B;
ll f[N],s[N];
ll x[N];
struct SegmentTree{
ll mi[4*N];
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x){
	mi[x]=min(mi[ls],mi[rs]);
}
void build(int x,int l,int r){
	if(l==r){
		mi[x]=inf;return;
	}
	mi[x]=inf;
	build(ls,l,mid);build(rs,mid+1,r);
}
void upda(int x,int l,int r,int p,ll c){
	if(l==r){
		mi[x]=min(mi[x],c);return;
	}
	if(p<=mid) upda(ls,l,mid,p,c);
	else upda(rs,mid+1,r,p,c);
	pushup(x);
}
ll query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return mi[x];
	}
	ll ret=inf;
	if(L<=mid) ret=min(ret,query(ls,l,mid,L,R));
	if(mid<R) ret=min(ret,query(rs,mid+1,r,L,R));
	return ret;
}

}sg[2];
ll dp(){
	memset(f,0x3f,sizeof f);
	memset(s,0,sizeof s);
	sg[0].build(1,1,n);sg[1].build(1,1,n);
	s[0]=0;s[1]=abs(x[1]-B);
	for(reg i=2;i<=q;++i) s[i]=s[i-1]+abs(x[i]-x[i-1]);
	
	sg[0].upda(1,1,n,A,-A);
	sg[1].upda(1,1,n,A,A);
	
	ll mi=0;
	for(reg i=1;i<=q;++i){
		if(i==q){
			return s[i]+mi;
		}else{
			f[i]=min(sg[0].query(1,1,n,1,x[i+1])+x[i+1]+s[i],sg[1].query(1,1,n,x[i+1],n)-x[i+1]+s[i]);
			sg[0].upda(1,1,n,x[i],f[i]-s[i+1]-x[i]);
			sg[1].upda(1,1,n,x[i],f[i]-s[i+1]+x[i]);
			
			mi=min(mi,f[i]-s[i+1]);
		}
	}
	return 23333;
}
int main(){
	rd(n);rd(q);rd(A);rd(B);
	for(reg i=1;i<=q;++i) rd(x[i]);	  
	ll ans=dp();swap(A,B);ans=min(ans,dp());
	printf("%lld\n",ans);
	return 0;
}

}
signed main(){
    Miracle::main();
    return 0;
}

/*
   Author: *Miracle*
*/