#include<bits/stdc++.h>
using namespace std;
long long solve(){
  	int n;
	cin>>n;
  	long long A[n][n];
	long long dp[(1<<n)];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>A[i][j];
	dp[0]=0;
	for(int i=1;i<1<<n;i++){
		dp[i]=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				for(int k=j+1;k<n;k++){
					if(i&(1<<k)) dp[i]+=A[j][k];
				}
			}
		}
	}
	for(int mask=1;mask<1<<n;mask++){
		for(int ss=mask;ss>0;ss=(ss-1)&mask){
			dp[mask]=max(dp[mask],dp[ss]+dp[mask^ss]);
		}
	}
	return dp[(1<<n)-1];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve()<<"\n";
}