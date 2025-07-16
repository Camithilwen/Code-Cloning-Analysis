#include<iostream>
using namespace std;
long long n;
long long a[200003];
long long dp[200003];
long long sumb[200003];
long long ans=-2e18;
long long sum;
long long su; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1]=a[1];
	dp[2]=a[2];
	sumb[n]=a[n];
	sumb[n-1]=a[n-1];
	for(int i=3;i<=n;i++) dp[i]=dp[i-2]+a[i];
	for(int i=n-2;i>=1;i--) sumb[i]=sumb[i+2]+a[i];
	sum=dp[n];
	if(n%2==0){
		ans=max(dp[n-1],dp[n]);
		for(int i=1;i<=n;i+=2) ans=max(ans,dp[i]+sumb[i+3]);
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i%2==0) su+=a[i];
		else{
			su=max(su-a[i],-a[i]);
			ans=max(ans,sum+su);
		}
	}
	cout<<ans<<endl;
	return 0;
}