#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
#define outarr(a,L,R) printf(#a"[%d...%d] = ",L,R);\
						For(_v2,L,R)printf("%d ",a[_v2]);puts("");
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=2005,mod=998244353;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int del(int x,int y){
	return x-y<0?x-y+mod:x-y;
}
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
int n,m;
int dp[N][N];
const int BN=1000005;
int Fac[BN],Inv[BN],Iv[BN];
int C(int n,int m){
	if (m<0||m>n)
		return 0;
	return (LL)Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int IC(int n,int m){
	return (LL)Inv[n]*Fac[m]%mod*Fac[n-m]%mod;
}
void prework(){
	int n=BN-1;
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	Inv[n]=Pow(Fac[n],mod-2);
	Fod(i,n,1)
		Inv[i-1]=(LL)Inv[i]*i%mod;
	For(i,1,n)
		Iv[i]=(LL)Inv[i]*Fac[i-1]%mod;
}
namespace so60{
	void prework(){
		int n=3,m=3;
		For(i,0,n)
			For(j,0,m){
				if (i==0&&j==0)
					dp[i][j]=0;
				else if (i>=j){
					dp[i][j]=((LL)dp[i-1][j]*i%mod*Iv[i+j]+dp[i][j])%mod;
					if (j>0)
						dp[i][j]=((LL)(dp[i][j-1]+1)*j%mod*Iv[i+j]+dp[i][j])%mod;
				}
				else {
					dp[i][j]=((LL)dp[i][j-1]*j%mod*Iv[i+j]+dp[i][j])%mod;
					if (i>0)
						dp[i][j]=((LL)(dp[i-1][j]+1)*i%mod*Iv[i+j]+dp[i][j])%mod;
				}
			}
	}
	const int N=500005;
	int a[N],d[N],dd[N],ddd[N];
	int main(){
		prework();
		For(i,1,3){
			a[i]=dp[i][i];
			d[i]=(dp[i][i]-dp[i-1][i-1]+mod)%mod;
			dd[i]=(d[i]-d[i-1]+mod)%mod;
			ddd[i]=(LL)Pow(dd[i],mod-2)*Pow(2,i*2)%mod;
		}
		For(i,4,n){
			ddd[i]=(LL)ddd[i-1]*(i*4-2)%mod*Pow(i-2,mod-2)%mod;
			dd[i]=(LL)Pow(2,i*2)*Pow(ddd[i],mod-2)%mod;
			d[i]=(d[i-1]+dd[i])%mod;
			a[i]=(a[i-1]+d[i])%mod;
		}
		cout<<a[n]<<endl;
		return 0;
	}
}
int main(){
	prework();
	n=read(),m=read();
	if (n>m)
		swap(n,m);
//	if (n==m)
//		return so60::main();
	int ans=(LL)n*C(n+m,n)%mod;
	For(i,1,n)
		Del(ans,(LL)C(i+i-1,i)*C(n-i+m-i,n-i)%mod);
	ans=(LL)ans*IC(n+m,n)%mod;
	ans=(n+m-ans+mod)%mod;
	cout<<ans<<endl;
	return 0;
}