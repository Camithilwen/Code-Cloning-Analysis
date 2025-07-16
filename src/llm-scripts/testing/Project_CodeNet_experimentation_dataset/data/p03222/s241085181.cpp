#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=2e2+5,mod=1e9+7;
ll n,m,k,dp[N][N],num[N][N];
int main(){
	cin>>n>>m>>k;
	for(int s=0;s<(1<<(m-1));s++){
		bool ok=true;
		for(int j=0;j<m-1;j++){
			int b1=(s>>j)&1;
			int b2=(s>>(j+1))&1;
			if(b1==b2&&b1)	ok=false;
		}
		if(!ok)	continue;
		for(int j=0;j<m;){
			if((s>>j)&1){
				num[j][j+1]++,num[j+1][j]++;
				j+=2;
			}
			else{
				num[j][j]++;
				j++;
			}
		}		
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int p=0;p<m;p++)	dp[i+1][p]=(dp[i+1][p]+(dp[i][j]*num[j][p])%mod)%mod;
	cout<<dp[n][k-1]<<'\n';
	return 0;
}
