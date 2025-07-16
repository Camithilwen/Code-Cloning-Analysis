#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
int n,ans=0,cnt[5007],id[5007];
long long h[5007],p[5007],dp[5007];
bool cmp(int x,int y){
	return (h[x]+p[x]<h[y]+p[y]);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i]>>p[i];
		id[i]=i;
	}
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++) dp[i]=1e16;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			int t=id[i];
			if(dp[j]<=h[t]) dp[j+1]=min(dp[j+1],dp[j]+p[t]);
		}
	}
	for(int i=n;i>=0;i--){
		if(dp[i]!=1e16){
			cout<<i;
			return 0;
		}
	}
}
