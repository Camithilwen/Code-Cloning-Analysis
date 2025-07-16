#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include<cstring>
#include<climits>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 21) + 1], *p1 = buf, *p2 = buf;
inline int read() {
	bool f=0;int x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c==EOF)exit(0);if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return !f?x:-x;
}
#define MAXN 2000
#define INF 0x3f3f3f3f
#define Mod (int)(1e9+7)
LL fac[MAXN*MAXN+5],inv[MAXN*MAXN+5];
LL Pow(LL x,LL y){
	LL ret=1;
	while(y){
		if(y&1) ret=ret*x%Mod;
		x=x*x%Mod,y>>=1;
	}
	return ret;
}
void Prepare(){
	fac[0]=1;
	for(int i=1;i<=MAXN*MAXN;i++)
		fac[i]=fac[i-1]*i%Mod;
	inv[MAXN*MAXN]=Pow(fac[MAXN*MAXN],Mod-2);
	for(int i=MAXN*MAXN-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%Mod;
	return ;
}
LL f[MAXN+5][MAXN+5];
LL C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main(){
	Prepare();
	int n=read(),k=read();
	if(k==1)
		puts("1"),exit(0);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=1;
		for(int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]+C(n-i+(n-(j-1))*(k-1)-1,k-2)*f[i][j-1]%Mod)%Mod;
	}
	printf("%lld\n",f[n][n]*fac[n]%Mod);
	return 0;
}