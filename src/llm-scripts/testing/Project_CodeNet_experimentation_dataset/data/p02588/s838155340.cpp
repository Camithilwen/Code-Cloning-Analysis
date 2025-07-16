#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,f,ans;
double a[200001];
map<pair<int,int>,int> m;
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		int b=round(a[i]*1000000000);
		t=f=-9;
		while(b%2==0)
		{
			b/=2;
			t++;
		}
		while(b%5==0)
		{
			b/=5;
			f++;
		}
		m[make_pair(t,f)]++;
	}
	for(auto i:m)
		for(auto l:m)
			if(i.first.first+l.first.first>=0&&i.first.second+l.first.second>=0)
			{
				if(i==l)
					ans+=i.second*(i.second-1)/2;
				if(i<l)
					ans+=i.second*l.second;
			}
	cout<<ans;
	return 0;
}