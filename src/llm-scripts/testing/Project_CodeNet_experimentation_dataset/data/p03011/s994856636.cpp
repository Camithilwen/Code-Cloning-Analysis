#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string.h>
using namespace std;
#define pb push_back
#define all(v) v. begin(),v. end()
#define  rep(i,n,v) for(i=n;i<v;i++)
#define per(i,n,v) for(i=n;i>v;i--)
#define ff first 
#define ss second 
#define pp pair<ll,ll>
#define eps 1e-6
#define ll  long long
#define endl '\n'
void solve()
{
  ll n, a,m=0,b=1, k=0, i, j,l=2e9+7;
  string s, r, y;
  cin>>n>>a>>b;
  k=min(n+a,min(n+b,a+b));
  cout<<k;
  /*if(n<a) cout<<0;
  else cout<<10;*/
}
int main()
{
 ios_base::sync_with_stdio(false);
  cin. tie(0);cout. tie(0);
    ll t=1;
 //  cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}