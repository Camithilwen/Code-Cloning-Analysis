#include<cstdio>
typedef long long LL;
const int N=2003;
const int O=2*N;
int n,m,ans;
int dp[3*N][5*N];

inline LL Pow(LL x,int p) {
	if(p==0) return 1;
	if(!(p&1)) return Pow(x*x%m,p>>1);
	return x*Pow(x*x%m,p>>1)%m;
}
inline void Add(int &x,int y) {
	x+=y; if(x>=m) x-=m;
}
int main() {
	scanf("%d %d",&n,&m); n*=3;
	dp[0][O]=1;
	for(int s=0;s<=n;s++) {
		for(int D=-s/2;D<=s;D++) {
			int d=D+O;
			Add(dp[s+1][d+1],dp[s][d]);
			Add(dp[s+2][d-1],dp[s][d]*(s+1ll)%m);
			Add(dp[s+3][d],dp[s][d]*(s+1ll)%m*(s+2ll)%m);
		}
	}
	for(int i=0;i<=n;i+=3)
		Add(ans,dp[n][i+O]);
	printf("%d\n",ans);
	return 0;
}