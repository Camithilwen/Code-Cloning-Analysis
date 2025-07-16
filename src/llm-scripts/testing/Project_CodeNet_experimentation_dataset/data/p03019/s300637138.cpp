#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
    int x;
    char c;
    int f=1;
    while((c=getchar())!='-' && (c>'9' || c<'0'));
    if(c=='-') f=-1,c=getchar();
    x=c^'0';
    while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
    return x*f;
}
inline ll readll(){
    ll x;
    char c;
    int f=1;
    while((c=getchar())!='-' && (c>'9' || c<'0'));
    if(c=='-') f=-1,c=getchar();
    x=c^'0';
    while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
    return x*f;
}
const int maxn=1e5+10;
int id[maxn],b[maxn],l[maxn],r[maxn];
ll v[maxn];
inline bool cmp(const int A,const int B){
	return v[A]>v[B];
}
int main(){
	int n=read(),lim=read();
	ll tot=0;
	REP(i,1,n){
		b[i]=read(),l[i]=read(),r[i]=read(),id[i]=i;
		v[i]=(ll)l[i]*b[i]+(ll)r[i]*(lim-b[i]);
		tot-=(ll)l[i]*b[i];
	}
	sort(id+1,id+n+1,cmp);
	ll sum=0,ans=1e18;
	ll val=0;
	REP(i,1,n){
		int u=id[i];
		val=v[u];
		if(tot+v[u]>=0) break;
		tot+=v[u];
		sum+=lim;
	}
	REP(i,1,n) if(tot+v[i]>=0){
		if(v[i]>val) tot+=val-v[i];
		if(tot+(ll)l[i]*b[i]>=0){
			chkmin(ans,b[i]-(tot+(ll)l[i]*b[i])/l[i]);
		}
		else{
			chkmin(ans,lim-(tot+v[i])/r[i]);
		}
		if(v[i]>val) tot-=val-v[i];
	}
	printf("%lld\n",ans+sum);
    return 0;
}