#include<bits/stdc++.h>
using namespace std;
int n,ans,q[1<<17],f[1<<17],dp[1<<17],a[1<<17];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(q,0x3f,sizeof(q));
	for(int i=1;i<=n;i++){
		f[i]=upper_bound(q+1,q+n,-a[i])-q;
		q[f[i]]=-a[i];
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
 }
