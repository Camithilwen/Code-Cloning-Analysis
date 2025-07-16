#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;

ll f(pair<string,ll>&x ,pair<string,ll>&y) 
{
	if(x.first == y.first) 
	{
		return x.second>y.second;
	}
	else 
	{
		return x.first<y.first;
	}
}
 
void solve()
{
	ll a,b;
	cin>>a>>b;
	cout<<max(a+b,2*max(a,b)-1);
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
