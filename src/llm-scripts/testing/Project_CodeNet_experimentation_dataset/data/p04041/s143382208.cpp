#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
#define qwq
const int mod=1e9+7;
int dp[50][(1<<17)+7];
int n,x,y,z;
ll all_ans=1;
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	int gdans=(1<<(x+y+z-1))|(1<<(y+z-1))|(1<<(z-1));
	int limit=(1<<(x+y+z))-1;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		all_ans*=10;
		all_ans%=mod;
		for(int s=0;s<=limit;++s){
			if((s&gdans)==gdans)continue;
			for(int c=1;c<=10;++c){
				int k=((s<<c)|(1<<(c-1)))&limit;
				if((k&gdans)==gdans)continue;
				dp[i][k]+=dp[i-1][s];
				dp[i][k]%=mod;
			}
		}
	}
	ll ans=0;
	for(int s=0;s<=limit;++s){
		ans+=dp[n][s];ans%=mod;
	}
	printf("%lld\n",(all_ans-ans+mod)%mod);
	return 0;
}