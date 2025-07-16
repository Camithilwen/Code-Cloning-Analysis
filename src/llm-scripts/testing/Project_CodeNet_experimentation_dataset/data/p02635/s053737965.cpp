#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 303
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,gu,dp[N][N][N],a[N],ans,sum[N];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1),m=read();
	s[++n]='0';
	m=min(n,m);
	for(int i=1;i<=n;++i){
		if(s[i]=='0')++gu;
		else ++a[gu+1];
	}
	for(int i=1;i<=gu;++i){
		sum[i]=a[i]+sum[i-1];
	}
	dp[0][0][0]=1;
	for(int i=1;i<=gu;++i){
		for(int j=sum[i];j<=n-gu;++j){
			int lim=min(j,n-sum[i-1]-gu);
			for(int k=0;k<=m;++k){
				for(int p=0;p<=lim;++p){
					if(max(0,p-a[i])<=k)dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-p][k-max(0,p-a[i])])%mod;
				}
			}
		}
	}
	for(int k=0;k<=m;++k){
		ans=(ans+dp[gu][n-gu][k])%mod;
	}
	cout<<ans<<endl;
	return 0;
}

