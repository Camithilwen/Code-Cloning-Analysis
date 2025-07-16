#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
string a,b,c;

ll mod(ll a)
{
	if(a<inf)return a;
	else 
	return a%inf;
}
 void test_cases()
{

ll n;
cin>>n;
 vector<ll>cnt(n+1,0);
while(n>1)
{
	ll x=n;
for(ll i=2;i<=x;i++)
{
	while(x%i==0)
	{
		cnt[i]++;
		x=x/i;
	}
}
	n--;
}

ll ans=1;
for(auto x:cnt)
{	
 //cout<<x<<" ";
	ans*=(x+1);
	ans=mod(ans);
}
 
 cout<<ans;
 
}


int main()
{
    fast;
  ll t;
 // cin>>t;
 t=1;
  while(t--)
  test_cases();

  	
}

		
	
	
	
	
