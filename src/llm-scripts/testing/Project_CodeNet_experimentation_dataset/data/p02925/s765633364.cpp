		#include <bits/stdc++.h>
		using namespace std;
		typedef long long ll;
		#define PI 3.14159265358979
		#define EPS 1e-8
		#define mod  998244353
		#define fi first
		#define se second
		#define mp make_pair
		#define pb push_back
		#define endl "\n"
			 
		const ll INF=1e15;	
		const int N=2e5+50;
		 

		 
		long long binpow(long long a, long long b, long long m) {
			a %= m;
			long long res = 1;
			while (b > 0) {
				if (b & 1)
					res = res * a % m;
				a = a * a % m;
				b >>= 1;
			}
			return res;
		}
		
		ll modinverse(ll a,ll m)
		{
			return binpow(a,m-2,m);
		}
		
		
		int main()
		{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);cout.tie(0);
			
			ll n;
			cin>>n;
			stack<ll> st[1005];
			for(ll i=1;i<=n;i++)
			{
				vector<ll> v;
				for(ll j=1;j<n;j++)
				{
					ll val;cin>>val;
					v.pb(val);
				}
				
				reverse(v.begin(),v.end());
				
				for(ll j=0;j+1<n;j++)
				{
					st[i].push(v[j]);
				}
			}
			
			ll cnt=0;
			ll c1=0;
			while(c1<((n*(n-1))/2))
			{
				ll c=0;
				cnt++;
				vector<ll> vis(1005,0);
				for(ll i=1;i<=n;i++)
				{
					if(!st[i].empty() && !vis[i])
					{
						ll j=st[i].top();
						if(!st[j].empty() && st[j].top()==i && !vis[j])
						{
							//cout<<i<<" "<<j<<endl;
							st[i].pop();
							st[j].pop();
							c=1;
							c1++;
							vis[i]=vis[j]=1;
						}
					}
				} 
				if(!c)
				{
					cout<<-1;
					exit(0);
				}
			}
			cout<<cnt;
		}
			
			
		
