#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define rg register 
#define go(i,x,a) for(rg int i=a;i<x;i++)
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

const int maxn=5e5+5;
int n,a[maxn],b[maxn],hx[maxn],tl,s0[maxn],q[maxn],tt;
ll ans,f[maxn][2];
vector<int>g[maxn];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc == '-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

inline void add(ll &a,ll b){ a=a+b; if(a >= mod) a-=mod; return; }
inline void dec(ll &a,ll b){ a=a-b; if(a < 0) a+=mod; return ; }

inline  void cal(int x){
	tt=0;
	go(i,g[x].size(),0) q[++tt]=g[x][i];
	ll sa=1,sb=0;
	go(i,tt+1,1){
		ll ss=s0[q[i]]-s0[q[i-1]];
		add(sa,sb*ss%mod);
		add(sb,sa); 
	}
	if(q[tt] != n){
		ll ss=s0[n]-s0[q[tt]];
		add(sa,sb*ss%mod);
	}
	add(ans,b[n] == 0 ? sb : sa);
}

inline ll qpow(int x,int k){
	ll ss=1,tmp=x;
	while(k > 0){
		if(k & 1) ss=ss*tmp%mod;
		tmp=tmp*tmp%mod;
		k>>=1;
	}
	return ss;
}

int main(){
	n=rd();
	go(i,n+1,1){
		a[i]=rd();	b[i]=b[i-1]^a[i];
		if(b[i]) hx[++tl]=b[i];
	}
//	go(i,n+1,1) printf("%d ",b[i]);	puts("");
	go(i,n+1,1) s0[i]=s0[i-1]+(b[i] == 0);
	sort(hx+1,hx+tl+1); tl=unique(hx+1,hx+tl+1)-hx-1;
//	go(i,tl+1,1) printf("%d ",hx[i]); puts("");
	go(i,n+1,1)
		if(b[i]) b[i]=lower_bound(hx+1,hx+tl+1,b[i])-hx;
	go(i,n+1,1) g[b[i]].push_back(i);
	if(b[n] == 0){
		go(i,tl+1,1) cal(i);//,printf("%d: %lld\n",hx[i],ans);
		add(ans,qpow(2,s0[n]-1));
	}else cal(b[n]);
	printf("%lld",ans);
	return 0;
}