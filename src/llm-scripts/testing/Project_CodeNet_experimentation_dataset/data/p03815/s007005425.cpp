#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

void solve()
{
	ll x;
	cin>>x;
	if(x<=6)
		cout<<1;
	else if(x<=11)
		cout<<2;
	else if(x%11>6)
		cout<<(x/11)*2+2;
	else if(x%11==0)
		cout<<(x/11)*2;
	else
		cout<<(x/11)*2+1;
	return;
}

int main()
{
	fast;
	ll q=1;
	// cin>>q;
	while(q--)
		solve();
	return 0;
}

