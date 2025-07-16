#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
#define N 321
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
int n,a[N],dp[N*N],sum,ans;
int main(){
	n=read();
	ans=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		ans=3LL*ans%mod;
	}
	dp[0]=1;
	for(int i=1;i<=n;++i){
		sum+=a[i];
		for(int j=sum;j>=0;--j){
			(dp[j]<<=1)%=mod;
			if(j>=a[i])dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	for(int i=sum;sum-i<=i;--i){
		ans=(ans-3LL*dp[i]%mod+mod)%mod;
	}
	if(!(sum&1)){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=n;++i){
			for(int j=sum;j>=a[i];--j){
				dp[j]=(dp[j]+dp[j-a[i]])%mod;
			}
		}
		ans=(ans+3LL*dp[sum>>1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}

