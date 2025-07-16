#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mod 998244353
#define inv2 499122177
#define M 1000020
using namespace std;
namespace IO{
	int Top=0; char SS[20];
	void write(int x){
		if(!x){putchar('0');return;} if(x<0) x=-x,putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) putchar(SS[Top]+'0'),--Top;
	}
	int read(){
		int nm=0,fh=1; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return nm*fh;
	}
}using namespace IO;
int mul(int x,int y){return (LL)x*(LL)y%mod;}
int add(int x,int y){return (x+y>=mod)?x+y-mod:x+y;}
int mus(int x,int y){return (x-y<0)?x-y+mod:x-y;}
int qpow(int x,int sq){
	int res=1;
	for(;sq;sq>>=1,x=mul(x,x)) if(sq&1) res=mul(res,x);
	return res;
}
int n,m,fac[M],ifac[M],ans;
int C(int tot,int tk){return mul(fac[tot],mul(ifac[tot-tk],ifac[tk]));}
int main(){
	n=read(),m=read(),fac[0]=1; if(n>m) swap(n,m);
	for(int i=1;i<=n+m;i++) fac[i]=mul(fac[i-1],i); ifac[n+m]=qpow(fac[n+m],mod-2);
	for(int i=n+m;i;i--) ifac[i-1]=mul(ifac[i],i); 
	for(int i=1;i<=n;i++) ans=add(ans,mul(C(i<<1,i),C(n+m-(i<<1),n-i)));
	write(add(mul(ans,mul(inv2,qpow(C(n+m,m),mod-2))),m)),putchar('\n'); return 0;
}