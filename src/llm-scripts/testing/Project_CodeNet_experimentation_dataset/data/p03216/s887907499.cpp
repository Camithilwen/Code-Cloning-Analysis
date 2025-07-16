#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M = 1e6+6;
ll seg[4*M],lazy[4*M],ct[4*M];
ll ans[100];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	s = "$"+s;
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		ll ans = 0;
		ll m = 0;
		ll d = 0;
		ll cur = 0;
		for(int i=1;i<=n;i++)
		{
			if(i>k)
			{
				// delete i-k
				if(s[i-k] == 'D')
				{
					cur -= m;
					d--;
				}
				if(s[i-k] == 'M')
				{
					m--;
				}
			}
			if(s[i] == 'D')
				d++;
			if(s[i] == 'M')
			{
				m++;
				cur += d;
			}
			if(s[i] == 'C')
				ans += cur;
		}
		cout<<ans<<"\n";
	}
	return 0;
}