#include <bits/stdc++.h>
using namespace std;
typedef long long int  ll;
ll  v[200009];
int main() {
	// #ifndef ONLINE_JUDGE
	// 	// for getting input from input.txt
	// 	freopen("input.txt", "r", stdin);
	// 	// for writing output to output.txt
	// 	freopen("output.txt", "w", stdout);
	// #endif
	ll n,t,ans =0;
	cin>>n>>t;
	// ans = t;
	// vector<ll> v(n,0);
	for (ll i = 1; i <=n; ++i)
	{
		cin>>v[i];
	}
	for (ll i = 1; i <= n-1; ++i)
	{
		if(v[i+1] - v[i] <= t){
			ans = ans + (v[i+1]-v[i]);
		}	
		else{
			ans = ans + t;
		}
	}

	cout<<ans+t<<"\n";
	return 0;
    }
	