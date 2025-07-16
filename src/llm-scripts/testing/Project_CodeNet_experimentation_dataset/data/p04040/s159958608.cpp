#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)

#define int long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MOD=1e9+7,MAXN=200000+10;

int fac[MAXN],inv[MAXN];

int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}

int c(int m,int n) {
	if(n==m||!m||!n) return 1;
	return ((fac[m]*inv[n]%MOD)*inv[m-n])%MOD;
}

int calc(int x_1,int y_1,int x_2,int y_2) {
	return c(abs(x_2-x_1)+abs(y_2-y_1),abs(x_2-x_1));
}

signed main() {
	int h=read(),w=read(),a=read(),b=read();
	fac[0]=1;
	REP(i,1,h+w) fac[i]=(fac[i-1]*i)%MOD;
	
	REP(i,1,h+w) inv[i]=qpow(fac[i],MOD-2);
	int ans=0;	
	REP(i,1,h-a) {
		ans=(ans+calc(1,1,b,i)*(calc(b+1,i,w,h)))%MOD;
	}
	
	printf("%lld\n",ans%MOD);
	return 0;
}