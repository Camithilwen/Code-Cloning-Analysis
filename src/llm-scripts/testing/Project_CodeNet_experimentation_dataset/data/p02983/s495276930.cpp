#include<bits/stdc++.h>
using namespace std;
long  long  l,r;

int main()
{
	scanf("%lld%lld",&l,&r);
	long long ans=2019;
	for(long long i=l;i<=r;++i)
	{
		for(long long j=i+1;j<=r;++j)
		{
			ans=min(ans,(i*j)%2019);
			if(ans==0)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}