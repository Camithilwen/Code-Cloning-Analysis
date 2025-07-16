#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],d,n,ans;
int dpl[200010],dpr[200010];
signed main(){
	cin>>n>>d;
	for(int i=1 ;i<=n;i++)cin>>a[i],ans+=a[i];
	ans+=(n-1)*d;
	dpr[1]=a[1];
	for(int i=2;i<=n;i++)dpr[i]=min(a[i],dpr[i-1]+d);
	dpl[n]=a[n];
	for(int i=n-1;i>=1;i--)dpl[i]=min(a[i],dpl[i+1]+d);
	for(int i=2;i<n;i++)ans+=min(dpl[i],dpr[i]);
	cout<<ans<<endl;
	return 0;
}
