#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,x,s[205];
int dp[205][100005],tot[100005];

int main(){
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	for(int i=0;i<=x;i++){
		int l=1,r=n,p=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(s[mid]<=i) p=max(p,mid),l=mid+1;
			else r=mid-1;
		}
		tot[i]=p;
	}
	dp[0][x]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			if(dp[i-1][j]==0) continue;
			for(int k=1;k<=tot[j];k++) (dp[i][j%s[k]]+=dp[i-1][j])%=mod;
			int p=n-tot[j];
			if(i<=p) (dp[i][j]+=1ll*(p-i+1)*dp[i-1][j]%mod)%=mod;
		}
	}
	int ans=0;
	for(int i=0;i<=x;i++) (ans+=1ll*i*dp[n][i]%mod)%=mod;
	printf("%d\n",ans);

	return 0;
}