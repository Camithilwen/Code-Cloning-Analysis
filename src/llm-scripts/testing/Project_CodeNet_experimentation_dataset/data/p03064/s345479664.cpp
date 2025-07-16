#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=998244353;
int dp[4][310*310],a[310];
inline int add_mod(int x){
	return x<mod?x:x-mod;
}
int main(){
	int n,ret=1,sum=0,minus=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		ret=(ll)ret*3%mod;
		minus=add_mod(minus+minus);
		sum+=a[i];
	}
	ret=add_mod(ret+mod-3);
	minus=add_mod(minus+mod-2);
	ret=add_mod(ret+mod-(ll)minus*3%mod);
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=a[i];j--){
			for(int s=0;s<4;s++){
				dp[s|1][j]=add_mod(dp[s|1][j]+dp[s][j-a[i]]);
				dp[s|2][j]=add_mod(dp[s|2][j]+dp[s][j-a[i]]);
			}
		}
	}
	for(int i=1;i+i<=sum;i++)
		ret=add_mod(ret+mod-(ll)dp[3][i]*3%mod);
	printf("%d\n",ret);
	return 0;
}