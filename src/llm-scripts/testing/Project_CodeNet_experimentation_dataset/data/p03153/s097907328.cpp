#include <bits/stdc++.h>
#define int long long
using namespace std;

int res,n,d,a[200010],dpl[200010],dpr[200010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>d;
	for(int i=1;i<=n;i++){cin>>a[i];res+=a[i];}
	res+=(n-1)*d;
	dpl[1]=a[1];
	for(int i=2;i<=n;i++) dpl[i]=min(a[i],dpl[i-1]+d);
	dpr[n]=a[n];
	for(int i=n-1;i>=1;i--) dpr[i]=min(a[i],dpr[i+1]+d);
	for(int i=2;i<=n-1;i++) res+=min(dpl[i],dpr[i]);
	cout<<res<<endl;
	return 0;
}