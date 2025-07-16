#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1000];
main()
{
	while(cin>>n>>m,n)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			ans+=a[i];
		}
		sort(a,a+n);
		for(int i=n-m;i>=0;i-=m)
		{
			ans-=a[i];
		}
		cout<<ans<<endl;
	}
}

