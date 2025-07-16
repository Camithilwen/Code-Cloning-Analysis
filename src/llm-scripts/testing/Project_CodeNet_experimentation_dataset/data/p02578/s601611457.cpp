#include<bits/stdc++.h>
using namespace std;

long long a[200000],l[200000];

signed main()
{
	ios::sync_with_stdio(0);
	
	long long n,i;
	long long ans=0;
	
	cin >> n;
	
	for(i=1; i<=n; i++)
		cin >> a[i];
		
	for(i=1; i<=n; i++)
		l[i]=max(a[i],l[i-1]);
		
	for(i=1; i<=n; i++)
		ans+=l[i]-a[i];
		
	cout << ans << endl;
	
	return 0;
}