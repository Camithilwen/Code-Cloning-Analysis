#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Fread {
	const int MAXN=1<<20;
	char buf[MAXN],*S,*T;
	inline char getchar() {
		if (S==T) {
			T=(S=buf)+fread(buf,1,MAXN,stdin);
			if (S==T) return EOF;
		}
		return *S++;
	}
}
inline int read() {
	int x(0),neg(1);
	char ch=getchar();
	while(!isdigit(ch)) {
		if (ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*neg;
}
#ifdef ONLINE_JUDGE
	#define getchar Fread::getchar
#endif
#define pb push_back
#define mp make_pair
int n,x,y,z;
int dp[45][1<<18];
const int mod=1e9+7;
inline int qpow(int x,int y) {
	int res=1ll;
	while(y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1; 
	}
	return res;
} 
//130624
/*
int cnt;
inline void dfs(int sum) {
	if (sum>17) return ;
	++cnt;
	for (int i=1;i<=10;++i) dfs(sum+i);
}
*/
signed main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
/*
	cnt=0;
	dfs(0);
	cout<<cnt<<'\n';
*/
	n=read(),x=read(),y=read(),z=read();
	int pnt=((1<<(x+y+z-1))|(1<<(y+z-1))|(1<<(z-1)));
//	cout<<pnt<<'\n';
	int tot=(1<<(x+y+z))-1;
	int ans=qpow(10,n);
	dp[0][0]=1;
	for (int i=1;i<=n;++i) {
		for (int j=0;j<=tot;++j) {
			if (dp[i-1][j]==0) continue;
			for (int k=1;k<=10;++k) {
				int now=((j<<k)+(1<<k-1))&tot;
				if ((now&pnt)!=pnt) {
					dp[i][now]=(dp[i][now]+dp[i-1][j])%mod;
				}
			}
		}
	}
	for (int i=0;i<=tot;++i) {
		ans=(ans-dp[n][i]+mod)%mod;
	}
	printf("%lld\n",ans); 
	return 0;
}
