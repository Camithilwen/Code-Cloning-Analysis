#include<bits/stdc++.h>
using namespace std;
const int N=(1<<18);
const int mod=1e9+7;
int dp[50][N];
int n,a,b,c;
int main()
{
	//freopen("H:\\c++1\\in.txt","r",stdin);
	//freopen("H:\\c++1\\out.txt","w",stdout);
	scanf("%d",&n);
	scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);
	int bz=(1<<(a-1))|(1<<(a+b-1))|(1<<(a+b+c-1));
	int mx=(1<<(a+b+c));
	dp[0][0]=1;
	int p=1;
	for(int i=1;i<=n;i++){
		p=(1ll*10*p)%mod;
		for(int j=0;j<mx;j++){
			if(dp[i-1][j]==0)continue;
			for(int k=1;k<=10;k++){
				int now=(j<<k)|(1<<(k-1));
				now&=(mx-1);
				if((now&bz)!=bz){
					dp[i][now]=(dp[i][now]+dp[i-1][j])%mod;
				}
			}
		}	
	}
	int ans=p;
	for(int i=0;i<mx;i++){
		ans=(ans-dp[n][i]+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}