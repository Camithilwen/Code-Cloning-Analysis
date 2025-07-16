#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
 


int main()
{
	//ifstream cin("input.txt");
	int n, q;
	string s;
	cin>>n>>q;
	cin>>s;
	
	vi cnt(n, 0);
	rep(i, 1, n- 1)
	{
		if(s[i-1] == 'A' && s[i] == 'C')
			cnt[i] = 1 + cnt[i-1];
		else
			cnt[i] = cnt[i-1];
	}

	rep(i, 1,q)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		cout<<cnt[r] - cnt[l]<<"\n";
	}
	
}