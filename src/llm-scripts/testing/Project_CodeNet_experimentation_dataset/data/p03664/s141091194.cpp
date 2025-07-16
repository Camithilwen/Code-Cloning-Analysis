#include<bits/stdc++.h>
using namespace std;
template<typename T>bool chkmax(T &a,T b){
	if(a<b){a=b;return 1;}
	else return 0;
}
template<typename T>T read(){
	T x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int maxn=1<<15;
int n,m,S,sum,ans=2e9,c[15][15],p[maxn],dp[maxn][15];
void init(){
	memset(dp,-1,sizeof dp);
	S=1<<n;
	for(int s=0;s<S;++s)
		for(int i=0;i<n;++i){
			if(((s>>i)&1)==0)continue;
			for(int j=i+1;j<n;++j)
				if((s>>j)&1)p[s]+=c[i][j];
		}
	dp[1][0]=0;
}
void solve(){
	n=read<int>(),m=read<int>();
	for(int u,v,w;m--;){
		u=read<int>()-1;
		v=read<int>()-1;
		w=read<int>();
		c[u][v]=c[v][u]=w;
		sum+=w;
	}
	init();
	for(int s=0;s<S;++s){
		for(int i=0;i<n;++i){
			if(!~dp[s][i])continue;
			int x=((S-1)^s)|(1<<i);
			for(int t=x;~t;--t)
				t&=x,chkmax(dp[s|t][i],dp[s][i]+p[t]);	
			for(int j=0;j<n;++j)if((~(s>>j)&1)&&c[i][j]){
				chkmax(dp[s|(1<<j)][j],dp[s][i]+c[i][j]);
			}
		}
	}
	for(int i=0;i<S;++i)
		ans=min(ans,sum-dp[i][n-1]);
	printf("%d\n",ans);
}
int main(){
	solve();
	
	return 0;
}