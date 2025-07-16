#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (long long)((a).size())

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    ll mod = 1e9+7;
    ll n,i,j,m;
    cin>>n>>m;
    vector<ll> x(n), y(m);
    for(i=0;i<n;i++) cin>>x[i];
    for(i=0;i<m;i++) cin>>y[i];
    ll xs = 0, ys = 0;
    for(i=0;i<n;i++)
    {
       xs = (xs + (i*x[i] - (n-i-1)*x[i]))%mod; 
    }
    for(i=0;i<m;i++)
    {
        ys = (ys + (i*y[i] - (m-i-1)*y[i]))%mod; 
    }
    ll ans = (xs*ys)%mod;
    cout<<ans;
}
