#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
void solve()
{
	ll n;
	cin>>n;
	vector<ll> x(n);
	for(ll i=0;i<n;i++)
		cin>>x[i];
	sort(x.begin(),x.end());
	ll a=0,b=0,c=0;
	for(ll i=n-1;i>=0;i--)
	{
		if(x[i]==x[i-1])
		{
			// cout<<x[i];
			a=x[i];
			c=i-1;
			break;
		}
	}
	// cout<<c<<a;
	for(ll i=c-1;i>=0;i--)
	{
		if(x[i]==x[i-1])
		{
			b=x[i];
			break;
		}
	}
	cout<<a*b;
	return;
}


int main()
{
	fast;
	ll q;
	q=1;
	// cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}
