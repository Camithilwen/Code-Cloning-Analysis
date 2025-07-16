#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

void solve()
{
	ll n;
	cin>>n;
	map<ll,ll> mp;
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		mp[x]++;
	}
	// cout<<mp[16];
	for(auto c:mp)
	{
		ans+=(c.second%2);
	}
	cout<<ans;
	return;
}
int main()
{
	fast;
	int q;
	q=1;
	// cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}