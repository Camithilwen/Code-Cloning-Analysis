#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=1000005;
const int mod=998244353;
int fac[maxn],facinv[maxn];
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline int C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
inline void prprpr(){	
	fac[0]=1;
	rep(i,1,1000000)fac[i]=1ll*fac[i-1]*i%mod;
	facinv[1000000]=powmod(fac[1000000],mod-2);
	per(i,999999,0)facinv[i]=1ll*facinv[i+1]*(i+1)%mod;
}
int n,m;
int main(){
	read(n);read(m);prprpr();
	if(n<m)swap(n,m);//cout<<facinv[1000000]<<endl;
	int ans=n;//cout<<C(2,1)<<endl;
	int d=powmod(C(n+m,n),mod-2);
	rep(i,1,m){
		ans=(ans+1ll*C(2*i-1,i)*C(n+m-2*i,n-i)%mod*d%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
