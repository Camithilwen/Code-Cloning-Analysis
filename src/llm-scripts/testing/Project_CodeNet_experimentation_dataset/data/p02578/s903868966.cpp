#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans=0,a,b;
int main()
{
	cin>>n;
	cin>>a;
	for(int i=1;i<=n-1;i++)
	{
		cin>>b;
		if(b<a) ans+=a-b;
		else a=b;
	}
	cout<<ans;
return 0;
}
