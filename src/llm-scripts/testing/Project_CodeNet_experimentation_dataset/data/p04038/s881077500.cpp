#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read() {
	int res=0,fh=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')fh=-1,ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return fh*res;
}

const int maxn=4000010;
const int mod=1e9+7;

int fac[maxn],inv[maxn];
inline int fpw(int x,int a){
	int ans=1;
	while(a){
		if(a&1) (ans*=x)%=mod;
		(x*=x)%=mod;
		a>>=1;
	}
	return ans;
}
inline int C(int n,int m){
	return (((fac[m]*inv[n])%mod)*inv[m-n])%mod;
}

#define LL int
#define inv_fac inv
#define Mod mod
#define re register
#define Maxn maxn
inline void pre(){
	fac[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=(fac[i-1]*i)%mod;
	inv[maxn-1]=fpw(fac[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)
		inv[i]=(inv[i+1]*(i+1))%mod;
}


int n,k;
int f[2010][2010];
//f[i][j] 表示在这些位置上已经放了i个白球，j种其他颜色的球。(i<j)

signed main(){
	n=read();if((k=read())==1) return puts("1"),0;
	pre();
	memset(f,0,sizeof f);f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			f[i][j]=f[i-1][j];
			if(!j) continue;
			(f[i][j]+=f[i][j-1]*(n-j+1)%mod*C(k-2,n-i+(n-j+1)*(k-1)%mod-1)%mod)%=mod;
		}
	}
	return printf("%lld",f[n][n]%mod),0;
}
