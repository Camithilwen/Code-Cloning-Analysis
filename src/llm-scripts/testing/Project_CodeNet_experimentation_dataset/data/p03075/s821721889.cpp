#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

void solve()
{

	ll a[5];
	for(ll i=0;i<5;i++)
		cin>>a[i];
	ll k;
	cin>>k;
	for(ll i=0;i<5;i++)
		for(ll j=0;j<5;j++)
			if(a[j]-a[i]>k)
			{
				cout<<":(";
				return;
			}
	cout<<"Yay!";
	return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}
