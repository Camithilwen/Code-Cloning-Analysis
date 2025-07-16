#include <bits/stdc++.h>
using namespace std;
bool a[1000005],b[1000005];
const int mod=1e9+7;
int main()
{
	int n,m;
	cin>>n>>m;
	long long sum=1;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(a[x])
		{
			cout<<"0";
			return 0;
		}
		a[x]=1;
	}
	for(int i=0;i<m;i++)
	{
		int y;
		cin>>y;
		if(b[y])
		{
			cout<<"0";
			return 0;
		}
		b[y]=1;
	}
	int k1=0,t1=0;
	for(int i=n*m;i>0;i--)
	{
		int k2=k1,t2=t1;
		if(b[i])
		{
			k2=1;
			k1++;
		}
		if(a[i])
		{
			t2=1;
			t1++;
		}
		if(a[i]||b[i])
			sum*=(k2*t2)%mod;
		else
			sum*=(k2*t2-(n*m-i))%mod;
		sum%=mod;
	}
	cout<<sum%mod;

	return 0;
}